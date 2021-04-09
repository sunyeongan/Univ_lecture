import numpy as np, cv2

#히스토그램은 어떤 데이터가 얼마나 많은지를 나타내는 도수 분포표플 그래프로 나타낸 것이다.
#가로축이 계급, 세로축이 빈도수 이다.


# 1. 컬러이미지를 그레이스케일을 통해서 흑백이미지로 바꾼다
# 2. 흑백이미지에서 0~255사이의 값을 뽑아낼 수 있도록 리스트append한다
# 3. 그래프를 그리기 위해선 x,y축이 필요하다 히스토그램에서는 x축->계급의 수, y축은 빈도수
# 4. 딕셔너리를 이용해서 key에는 계급, value에는 빈도수를 넣는다.
# 4. 막대모양 히스토그램을 그리기 위해선 각 계급마다 사각형의 넓이를 계산해야한다.
# 5. 사각형의 넓이는 가로 : (i + (i+1)) 세로 : 한 계급의 y절편
# 6. #전체 픽셀중에 가장 큰값과 가장 작은값을 알아야함 -> 히스토그램 스트레칭
# 새 화소값 = (화소값-low)*255/(high-low)


histo_255 = np.zeros((285*400)+1)
histo = {}
newhisto = {}
image = cv2.imread("images/low2.jpg", cv2.IMREAD_GRAYSCALE)

print(image[0].shape)
print(image.shape)

num1  = 0

for i in range(image.shape[0]):
    for o in range(image.shape[1]):
        k = image[i, o]
        histo_255[num1] = k
        num1 = num1+1
print(histo_255)


cv2.imshow("image",image)
cv2.waitKey(0)



# 리스트에서 받은 픽셀 데이터를 딕셔너리에 저장하고 빈도수를 value에 저장하는 과정
for i in range(256):
    histo[i] =0; #value값을 0으로 모두 초기화

# key = 계급수 , value = 빈도수
for j in histo_255:
    if(j in histo):
       histo[j]+=1 #histo의 value값을 1씩 증가한다.
    else:
        histo[j] = 1
print(histo)


#2번째 히스토그램 만들
min_p = min(map(min, image))
max_p = max(map(max, image))

for i in range(256):# 리스트의 길이만큼
    #가장 큰 화소값, 작은 화소을 찾기
    newhisto[i] = 0; # newhiso의 value값을 0으로 초기




print("high value",max_p)
print("low value",min_p)


h,i=image.shape[0],image.shape[1]

for h1 in range(h):
    for i1 in range(i):
        image[h1][i1]=((image[h1][i1]-min_p)/(max_p-min_p))*255

num1  = 0

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


