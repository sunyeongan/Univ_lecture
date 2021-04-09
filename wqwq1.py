import cv2
import numpy as np

image = cv2.imread("images/low2.jpg",cv2.IMREAD_GRAYSCALE)
if image is None: raise Exception("영상파일 읽기 오류")

arr = np.zeros(256)
print(arr)

h,i=image.shape[0],image.shape[1] # 이미지 차원
print(h,i)

for h1 in range(h):
    for i1 in range(i):
        arr[image[h1][i1]]=arr[image[h1][i1]]+1

cv2.imshow("image",image)
cv2.waitKey(0)
for l in range(256):
    print(l,":",arr[l])

min_p = min(map(min, image))
max_p = max(map(max, image))

print(min_p,max_p)

for h1 in range(h):
    for i1 in range(i):
        image[h1][i1]=((image[h1][i1]-min_p)/(max_p-min_p))*255

a=(128-min_p)/(max_p-min_p)*255
print("a=",a)
arr2 = np.zeros(256)

for h1 in range(h):
    for i1 in range(i):
        arr2[image[h1][i1]]=arr2[image[h1][i1]]+1
for i in range(256):
    print(i,":",arr2[i])


cv2.imshow("image",image)
cv2.waitKey(0)


