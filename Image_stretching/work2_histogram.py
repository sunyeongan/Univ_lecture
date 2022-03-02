import cv2
import numpy as np

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
        a = 150
        b = 250
        #image[h1][i1] = (image[h1][i1] - min_p) * ((b - a) / (max_p - min_p)) + a
        image[h1][i1]=(image[h1][i1]-min_p)*((b-a)/(max_p-min_p))+a
        #min = c
        #max = d

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


