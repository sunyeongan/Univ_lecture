#include "Mafia.h"

char pick[10];
char pick2[50] = "번이 마피아로 지목 되었습니다.";



int main(int argc, char *argv[]) {
	struct sockaddr_in cliaddr;

	int i, j, count, nbyte, accp_sock, clilen = sizeof(struct sockaddr_in);
	int turn = 0;
	int numctz = 3; //시민 수 
	int vtlimit[2] = {3, 2};
	int n, ret;
	
	int time2; //timer	
	
	fd_set readfds;

	if (argc != 2) {
		printf("사용법 : %s portnumber\n",argv[0]);
		exit(0);
	}

	listen_sock = tcp_listen(INADDR_ANY, atoi(argv[1]),5);
	
	if(listen_sock == -1)
		errquit("tcp_listen fail");
	if(set_nonblock(listen_sock) == -1)
		errquit("set_nonblock fail");
	
	printf("클라이언트 연결을 기다리십시오...\n");

	for (count = 0; ; count++){
		
		if(count == 200000){

			fflush(stdout);//출력스트림
			count = 0;
		}


		accp_sock = accept(listen_sock, (struct sockaddr *)&cliaddr, &clilen);

		if(accp_sock == -1 && errno != EWOULDBLOCK)
			errquit("accpet fail");
		else if (accp_sock > 0){
			clisock_list[num_chat] = accp_sock;//연결된 소켓기술자 클라이언트 리스트에 저장
			if(is_nonblock(accp_sock) != 0 && set_nonblock(accp_sock) < 0)//nonblocking soke
				errquit("set_nonblock fail");
			addClient(accp_sock, &cliaddr);
			send(accp_sock, START_STRING, strlen(START_STRING),0);
			printf("%d번째 사용자 추가.\n",num_chat);
			sprintf(welcome,"%d번 사용자입니다.",num_chat);
			send(clisock_list[num_chat - 1], welcome, strlen(welcome),0);
		}

		if (num_chat == 5){ //game start
			
			printf("게임을 시작합니다.\n");		

			srand(time(NULL));
			mafia = rand() % 5; //마피아 정하기
			police = (mafia + 1) % 5;

			for(k = 0; k < num_chat; k++){//참여자들에게 게임 시작 메세지 보냄
				send(clisock_list[k], start_command2, strlen(start_command2),0);
			}

			while(1){

				re = 0;
				printf("\n낮이 밝았습니다.\n");
				FD_ZERO(&readfds);
				for (k = 0; k < num_chat; k++){

					send(clisock_list[k], morning, strlen(morning), 0);
					if (k == mafia)//마피아에게 마피아라고 메세지 보내기
						send(clisock_list[k], mfmsg, strlen(mfmsg), 0);
					if(k == police && pflag == 0)//경찰에게 경찰이라고 메세지 보내기
						send(clisock_list[k],plcmsg,strlen(plcmsg),0);
					if(k != mafia && k != police)
						send(clisock_list[k], ctzmsg, strlen(ctzmsg), 0);
					FD_SET(clisock_list[k],&readfds);
					send(clisock_list[k], chating, strlen(chating), 0);//채팅 시작 메세지 전송i

				}

				ret = select(maxArr(clisock_list,num_chat) + 1, &readfds, NULL, NULL, NULL);
				//낮 투표 전에 채팅 타임
				
				//signal(SIGALRM,handler);
				//alarm(60);
				
				int cd = 10;
				
				
							
				if(ret > 0){
					
					int j = 0;
					while(ret > 0) {
					
						if(FD_ISSET(clisock_list[j], &readfds)){
							
							memset(chatmsg,0,MAXLINE + 1);//채팅 버퍼 초기화
							while(cd >= 0){
								sleep(1);
								if( cd == 0){
									printf("투표 전 대화가 종료 되었습니다.\n");
									break;
								}
								printf("%d >> ", cd);
								cd = cd -1;	
								 
								if(recv(clisock_list[j], chatmsg, sizeof(chatmsg), 0) > 0){//채팅 받기 

									printf("사용자 %d의 메세지 : %s\n",clisock_list[j]-3,chatmsg);
									//sprintf(chatsend,"사용자 %d의 메세지 : %s\n",clisock_list[j]-3,chatmsg);
									for(int i  = 0; i < num_chat; i++){			
										if( j != i){
											sprintf(chatsend,"사용자 %d의 메세지 : %s\n",clisock_list[j]-3,chatmsg);
											if(send(clisock_list[i], chatsend, strlen(chatsend), 0) == -1){; //모든 사용자에게 채팅내용 전송								
												perror("send");
												break;
											}
											memset(chatsend,0,MAXLINE+1);
										}
										
										else{
											continue;
										}
									}
								}
											
								
								if(cd == 0)
									break;
							ret--;	
							}
							
						}
						j++;
						
						
					}
				}
				
					
					
				

			
				for(i = 0; i < num_chat; i++)
					nvote[i] = 0;
				for(k = 0 ; k < num_chat; k++){
					send(clisock_list[k], vote, strlen(vote), 0);
				}
				for (i = 0; i < turn; i++){

					sprintf(dieuser,"* %d 번\n", userid[i]);
					for(k = 0; k < num_chat; k++)
						send(clisock_list[k],dieuser,strlen(dieuser),0);//죽은 사람 참여자들에게 보내기
				}

	
				while(1){//투표시작


					int flag = 0;
					max = 0;

					if (indexx == 0){


						printf("투표를 시작하겠습니다.\n\n");

						printf("게임 턴 횟수 : %d\n\n", gturn);
					}

					for(i = 0; i < num_chat; i++){//투표 한 명씩
						
						send(clisock_list[indexx], order, strlen(order), 0);//

						while(1){

							errno = 0;
							nbyte = recv(clisock_list[indexx], vvote, MAXLINE, 0);//참여자자가 보낸 투표->vvote
							

							if(nbyte > 1){//참여자가 보낸 투표 메세지가 1바이트  이상이면
								indexx++;//인덱스 플러스
								break;
							}


							if ( nbyte == 0) {//아무것도 보내지 않았다면 
								removeClient(i);
							}
							else if (nbyte == -1 && errno == EWOULDBLOCK);
								continue;

						}

						if (!strncmp(vvote, "1", 1)){
							++nvote[0];
							strcpy(pick,vvote);
							pick[strlen(pick)-1]='\0';
							strcat(pick,pick2);
							for(k = 0; k < num_chat; k++)
								send(clisock_list[k],pick,strlen(pick),0);
						}
						else if (!strncmp(vvote,"2",1)){
							++nvote[1];
							strcpy(pick,vvote);
							pick[strlen(pick)-1]='\0';
							strcat(pick,pick2);
							for(k = 0; k < num_chat; k++)
								send(clisock_list[k],pick,strlen(pick),0);
						}
						else if (!strncmp(vvote,"3",1)){
							++nvote[2];
							strcpy(pick,vvote);
							pick[strlen(pick)-1]='\0';
							strcat(pick,pick2);
							for(k = 0; k < num_chat; k++)
								send(clisock_list[k],pick,strlen(pick),0);
						}
						else if (!strncmp(vvote,"4",1)){
							
							++nvote[3];
							strcpy(pick,vvote);
							pick[strlen(pick)-1]='\0';
							strcat(pick,pick2);
							for(k = 0; k < num_chat; k++)
								send(clisock_list[k],pick,strlen(pick),0);
						}
						else if (!strncmp(vvote,"5",1)){
							++nvote[4];
							strcpy(pick,vvote);
							pick[strlen(pick)-1]='\0';
							strcat(pick,pick2);
							for(k = 0; k < num_chat; k++)
								send(clisock_list[k],pick,strlen(pick),0);
						}

					
						for ( i = 0; i < num_chat; i++)
							printf("%d ", nvote[i]);
						printf("\n");
					
					}
			
	

					if (indexx == 5) {//투표끝

						printf("투표끝!");
						for (i = 0; i < num_chat; i++){

							if(nvote[i] >= vtlimit[gturn]) {

								flag = 1;
								max = i + 1;
							}
						}
						if (flag == 1){
							printf("1111");
							break;
						}
						else{

							for(i = 0; i < num_chat; i++)
								nvote[i] = 0;
							indexx = 0;
						}

					}
			}//투표시작 =while

						userid[turn] = max;       //죽은 사용자 번호
						turn++;
						printf("**마피아는 %d번입니다.**\n", mafia + 1);
						printf("**경찰은 %d번입니다.**\n\n", police + 1);
						printf("가장 많은 투표를 받은 사람은 %d번입니다\n", max);
						sprintf(votemsg, "%s %d번 입니다\n", voteresult, max);
						for (i = 0; i < num_chat; i++) {
							send(clisock_list[i], votemsg, strlen(votemsg), 0);
							if (i == max - 1)
								send(clisock_list[i], userdie, strlen(userdie), 0);
						}
						if (max == mafia + 1) { //마피아가 맞는 경우
							printf("%s\n 게임 종료\n", correct);
							for (i = 0; i < num_chat; i++) {
								send(clisock_list[i], correct, strlen(correct), 0);
								send(clisock_list[i], ctzvictory, strlen(ctzvictory), 0);
							}
							return;     //게임 종료
						}
						else {        //아닌 경우 (시민, 경찰)

							if (max == police + 1) {   //경찰이 죽음
								pflag = 1;
								printf("경찰이 죽었습니다.\n");
								for (i = 0; i < num_chat; i++)
									send(clisock_list[i], policedie, strlen(policedie), 0);//아니라는 말과 밤으로 넘어간다.
							}
							else {          //시민이 죽음
								numctz--;
								printf("\t남은 시민 수: %d명\n\n", numctz);
								if (pflag == 1 && numctz == 1) {
									for (i = 0; i < num_chat; i++)
										send(clisock_list[i], mafiavictory, strlen(mafiavictory), 0);
									return;
								}
								for (i = 0; i < num_chat; i++)
									send(clisock_list[i], incorrect, strlen(incorrect), 0);//아니라는 말과 밤으로 넘어간다.

							}
						}
						printf("밤이 되었습니다.\n\n");

						for (i = 0; i < num_chat; i++) {
							if (i == mafia) {   //마피아차례
								send(clisock_list[i], nightmsg, strlen(nightmsg), 0);//마피아 결정하라는 메시지
								while (1) {
									errno = 0;
									1 == 1; //nbyte = recv(clisock_list[i], vvote, MAXLINE, 0);
									nbyte = recv(clisock_list[mafia], target, MAXLINE, 0);//메세지 청취
									if (nbyte > 0) {
										indexx++; //
										break;   //while
									}
									if (nbyte == 0) {
										removeClient(i);
										continue;
									}
									else if (nbyte == -1 && errno == EWOULDBLOCK)
										continue;
									if (strstr(buf, EXIT_STRING) != NULL) {
										removeClient(i);
									}
								}

								userid[turn] = atoi(target);
								turn++;
								send(clisock_list[atoi(target) - 1], userdie, strlen(userdie), 0);
								if (atoi(target) - 1 == police) //마피아가 경찰을 죽이는 경우
								{
									pflag = 1;
									send(clisock_list[mafia], pcorrect_command, strlen(pcorrect_command), 0);
									for (i = 0; i < num_chat; i++)
										send(clisock_list[i], policedie, strlen(policedie), 0);
								}
								else { //시민을 죽이는경우
									send(clisock_list[mafia], pincorrect_command, strlen(pincorrect_command), 0);
									numctz--;
									printf("남은 시민 수: %d명\n", numctz);
									if (numctz == 1 && pflag == 0) {   // 시민 1명, 경찰 살아있는 경우
										for (i = 0; i < num_chat; i++) {
											if (i == police) {
												sprintf(police_nt, "\tuser%d번이 죽었습니다.\n", atoi(target));
												send(clisock_list[i], police_nt, strlen(police_nt), 0);
												send(clisock_list[i], police_command, strlen(police_command), 0);//경찰에게만

												while (1) {
													errno = 0;
													1 == 1; //nbyte = recv(clisock_list[i], vvote, MAXLINE, 0);
													nbyte = recv(clisock_list[police], target, MAXLINE, 0);//메세지 청취
													if (nbyte > 1) {

														indexx++; //
														break;   //while
													}
													if (nbyte == 0) {
														removeClient(i);
													}
													else if (nbyte == -1 && errno == EWOULDBLOCK)
														continue;
													if (strstr(buf, EXIT_STRING) != NULL) {
														removeClient(i);
													}
												}
												if (atoi(target) - 1 == mafia) {//경찰이 마피아를 맞출 경우
													send(clisock_list[police], victory, strlen(victory), 0);
													for (i = 0; i < num_chat; i++) {
														send(clisock_list[i], policevictory, strlen(policevictory), 0);
														send(clisock_list[i], ctzvictory, strlen(ctzvictory), 0);
													}
													return;    //마피아 잡고 게임 종료
												}
												else {     //  남은 시민 1명이 죽은 경우
													userid[turn] = atoi(target);
													for (i = 0; i < num_chat; i++) {
														send(clisock_list[i], policelose, strlen(policelose), 0);
														send(clisock_list[i], mafiavictory, strlen(mafiavictory), 0);
													}
													return;
												}
											}
										}
									}
									if (pflag == 1 && numctz == 1) {   //경찰이 죽고 시민 1명
										printf("시민의 수가 마피아의 수와 같습니다.\n★마피아의 승리★\n게임 종료\n");
										send(clisock_list[i], mafiavictory, strlen(mafiavictory), 0);
										return;
									}
								}
							}       //if mafia

						
						re = 0;
						gturn++;
						indexx = 0;//게임 턴
					}//두번째 while
				}  //게임을 시작합니다 if
			// start
		}//num_chat==5 start
		for (i = 0; i < num_chat; i++) {
			errno = 0;
			nbyte = recv(clisock_list[i], buf, MAXLINE, 0);
			if (nbyte == 0) {
				removeClient(i);
				continue;
			}
			else if (nbyte == -1 && errno == EWOULDBLOCK)
				continue;
			if (strstr(buf, EXIT_STRING) != NULL) {
				removeClient(i);
				continue;
			}
			buf[nbyte] = 0;
			for (j = 0; j < num_chat; j++)
				send(clisock_list[j], buf, nbyte, 0);
			printf("%s\n", buf);
		}
	} //for (첫번째)
	
	return 0;
} //main




void handler(int signo){
	printf("채팅 시간 60초가 지났습니다.\n");
	alarm(60);
}


void addClient(int s, struct sockaddr_in *newcliaddr) {
	char buf[20];

	inet_ntop(AF_INET, &newcliaddr->sin_addr, buf, sizeof(buf));
	printf("new client: %s\n", buf);
	clisock_list[num_chat] = s;
	num_chat++;

}
void removeClient(int s) {
	close(clisock_list[s]);
	if (s != num_chat - 1)
		clisock_list[s] = clisock_list[num_chat - 1];
	num_chat--;
	printf("채팅 참가자 1명 탈퇴 현재 참가자수 =%d\n", num_chat);
}
int getmax()
{
	int max = listen_sock;
	int i;
	for (i = 0; i < num_chat; i++)
		if (clisock_list[i] > max)
			max = clisock_list[i];
	return max;
}
int tcp_listen(int host, int port, int backlog) {
	int sd;
	struct sockaddr_in servaddr;
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		perror("socket fail");
		exit(1);
	}
	bzero((char*)&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(host);
	servaddr.sin_port = htons(port);
	if (bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("bind fail");
		exit(1);
	}
	listen(sd, backlog);
	return sd;
}
int set_nonblock(int sockfd) {
	int val;
	val = fcntl(sockfd, F_GETFL, 0);
	if (fcntl(sockfd, F_SETFL, val | O_NONBLOCK) == -1)
		return -1;
	return 0;
}
int is_nonblock(int sockfd) {
	int val;
	val = fcntl(sockfd, F_GETFL, 0);
	if (val & O_NONBLOCK)
		return 0;
	return -1;
}

int maxArr(int *sock, int number_cli){
	int maxNumber = sock[0];

	for (int i = 0; i<number_cli; i++){
		if(sock[i] > maxNumber){
			maxNumber = sock[i];
		}

	}

	return maxNumber;
}
