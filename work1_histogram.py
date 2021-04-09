#히스토그램은 어떤 데이터가 얼마나 많은지를 나타내는 도수 분포표플 그래프로 나타낸 것이다.
#가로축이 계급, 세로축이 빈도수 이다.


# 1. 컬러이미지를 그레이스케일을 통해서 흑백이미지로 바꾼다
# 2. 흑백이미지에서 0~255사이의 값 (화소값) 을 뽑아내서 리스트 혹은 딕셔너리에 저장한다.
# 3. 딕셔너리를 이용해서 key에는 계급, value에는 빈도수를 넣는다.
# 4. 전체 픽셀중에 가장 큰값과 가장 작은값을 알아야함 -> 히스토그램 스트레칭


import numpy as np, cv2

histo_255 = np.zeros((285*400)+1) # 이미지의 크기 만큼 행렬을 만든다

histo = {} # 이미지 스트레칭 전의 히스토그램
newhisto = {} # 이미지 스트레칭 후의 히스토그램

image = cv2.imread("images/low2.jpg", cv2.IMREAD_GRAYSCALE) # 이미지 로드

#이미지는 2차원 행렬이다.

print(image.shape[0])
print(image.shape[1])
print(image.shape)# 이미지의 크기 285*400


num1  = 0

for i in range(image.shape[0]):
    for j in range(image.shape[1]):
        k = image[i, j] # k는 이미지 화소값으로 초기화
        histo_255[num1] = k # histo_255의 행렬은 이미지 크기와 똑같은 행렬이다. 이 행렬에 이미지의 화소값 초기화 한다.
        num1 = num1+1
print(histo_255)#크기가 커서 대략적인 값만 나온다.


cv2.imshow("image",image)
cv2.waitKey(0) # 엔터키를 누르면 그 다음 코드가 실행된다.



# histo_255(배열)에 저장된 이미지의 화소값을  histo(딕셔너리)에 0~255사이의 값들만 저장
for i in range(256):
    histo[i] =0; #value값을 0으로 모두 초기화

# key = 계급수 , value = 빈도수
for j in histo_255:
    if(j in histo):# 만약 j가 histo의 key 값과 같다면
       histo[j]+=1 #histo의 value값을 1씩 증가한다.
print(histo) # 0~255번 화소값들의 빈도수를 출력한다.


#이미지 스트레칭 후에 히스토그램 만들기
# 새 화소값 = (화소값-low)*255/(high-low)

min_p = min(map(min, image))
max_p = max(map(max, image))

for i in range(256):

    newhisto[i] = 0; # newhiso의 value값을 0으로 초기


print("high value",max_p)# max_p -> high
print("low value",min_p) # min_p -> low


#이미지들의 화소값을 스트레칭 한다.
for i in range(image.shape[0]):
    for j in range(image.shape[1]):
        image[i][j]=((image[i][j]-min_p)/(max_p-min_p))*255

num1  = 0

#이미지 스트레칭 완료 후
for h in range(image.shape[0]):
    for i in range(image.shape[1]):
        k = image[h, i]
        histo_255[num1] = k
        num1 = num1+1
print(histo_255)


cv2.imshow("image",image)
cv2.waitKey(0)

# 리스트에서 받은 픽셀 데이터를 딕셔너리에 저장하고 빈도수를 value에 저장하는 과정
for i in range(256):
    newhisto[i] =0; #value값을 0으로 모두 초기화

# key = 계급수 , value = 빈도수
for j in histo_255:
    if(j in histo):
       histo[j]+=1 #histo의 value값을 1씩 증가한다.

print(histo)


