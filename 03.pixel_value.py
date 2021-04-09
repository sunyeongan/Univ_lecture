#영상 화소값 확인

import cv2

image = cv2.imread("images/pixel.jpg", cv2.IMREAD_GRAYSCALE)
if image is None:
    raise Exception("영상파일 읽기 오류")

(x,y),(w,h) = (180,37), (15, 10)
roi_img = image[y:y+h, x:x+w] #행렵접근 ->y.x

print("[roi_img] = ")
for row in roi_img: #원소 순회방식 출력
    print("\n")
    for p in row:
        print("%4d" % p, end=" ") # 순회 원소 하나씩 출력

print("")

cv2.rectangle(image,(x,y,w,h), 255, 1) # 관심영역에 사각형 표시
cv2.imshow("image", image)
cv2.waitKey(0)