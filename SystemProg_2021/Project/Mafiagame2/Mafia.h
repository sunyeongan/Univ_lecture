#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/file.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>


#define MAXLINE 511
#define MAX_SOCK 1024

char *EXIT_STRING = "exit";
char *START_STRING = "방에 입장하였습니다. 게임 대기중입니다..\n";
char *start_command1 = "start";
char *start_command2 = "\nGAME START\n";
char welcome[MAXLINE + 1];

char chatsend[MAXLINE + 1];
char buf[MAXLINE + 1];
char cuf[MAXLINE + 1];
int maxfdp1;
int num_chat = 0;
int max;
int nnbyte;
int mafia, police;
int k, pflag = 0;
char *mfmsg = "당신은 마피아입니다.\n";
char *plcmsg = "당신은 경찰입니다. 밤에 마피아가 누군지 알수 있는 기회가 부여됩니다.\n";
char *ctzmsg = "당신은 시민입니다. 마피아를 찾아주세요\n";
char *chating = "투표 전에 참여자들과 이야기를 나누세요\n";
char *morning = "\n\t낮이 밝았습니다. 마피아가 누구일지 결정해주세요\n";
char *nightmsg = "\t누구를 죽일 것인지 정해주세요: ";
char *vote = "------------------------------------------------------\n\t\t투표를 시작합니다.\n\t마피아라고 생각하는 사용자의 번호를 입력하세요\n";
char *voteresult = "------------------------------------------------------\n\t가장 많은 투표를 받은 사람은";
char *votenotice = "다음 사용자들을 제외하고 투표하세요)";
char *userdie = "\t사용자는 죽었습니다..투표에서 0을 눌러주세요\n";
char *victory = "\t그는 마피아입니다.\n\n";
char *nvictory = "\t그는 마피아가 아닙니다.\n";
char *mafiavictory = "\t★★★마피아의 승리입니다★★★\n";
char *ctzvictory = "\t★★★시민의 승리입니다★★★\n";
int morningvote[5];
char fbuf[MAXLINE + 1];
clock_t g_startTime, g_endTime;
int clisock_list[MAX_SOCK];
int userid[5];
int nvote[5] = { 0 };
int listen_sock;
int valid = 0;
int re;
int turn = 0;
int gturn = 0;  //게임 턴 횟수
int n = 0;
int indexx = 0;
int invalid = 0;
void addClient(int s, struct sockaddr_in *newcliaddr);
void removeClient(int s);
int tcp_listen(int host, int port, int backlog);
int set_nonblock(int sockfd);
int is_nonblock(int sockfd);
char target[MAXLINE + 1];
char dieuser[5];
int getmax();
int sbyte;
char *policedie = "\t경찰이 죽었습니다.\n\t*******조심하세요!********\n";
char *policevictory = "\t★똑똑한 경찰이 마피아를 잡았습니다★\n\n";
char *policelose = "\t멍청한 경찰이 마피아를 못잡았습니다.\n";
char votemsg[MAXLINE + 1];
char vvote[MAXLINE + 1];

char chatmsg[MAXLINE + 1];
char police_nt[MAXLINE + 1];
char *correct = "\t그는 마피아가 맞습니다!\n\n";
char *incorrect = "\t선량한 시민이 죽었습니다.\n\n\t밤이 되었습니다.\n";
char *pcorrect_command = "\t경찰이 죽었습니다. 시민 수와 동일해질때까지 살아남으세요\n";
char *pincorrect_command = "\t시민이 죽었습니다.\n\n";
char *police_command = "\t경찰은 마피아로 의심되는 사람을 지목하세요\n";
char *order = "your turn. choice number. ";
char *wait_so = "wait..\n";
char *interrupt = "비정상적인 종료입니다. 게임을 다시 시작하세요.\n";
void addClient(int s, struct sockaddr_in *newcliaddr);
void removeClient(int s);
int tcp_listen(int host, int port, int backlog);
int set_nonblock(int sockfd);
int is_nonblock(int sockfd);
int maxArr(int *sock, int number_cli);
void handler(int signo);
void errquit(char *mesg)
{
	perror(mesg);
	exit(1);
}
