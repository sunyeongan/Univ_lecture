import numpy as np, cv2

def calc_histo(image, histSize, ranges=[0, 256] ):
    hist = np.zeros((histSize, 1), np.float32) #히스토그램 누적 행렬
    gap = ranges[1] / histSize

    for row in image:
        for pix in row:
            idx = int(pix/gap)
            hist[idx] += 1
    return hist

image = cv2.imread("images/pixel.jpg", cv2.IMREAD_GRAYSCALE)
if image is None:
    raise Exception("영상파일 읽기 오류")

histSize, ranges = [32], [0, 256]
gap = ranges[1]/histSize[0] # 계급간격
ranges_gap = np.arange(0, ranges[1]+1, gap)

hist1 = calc_histo(image, histSize, ranges)
hist2 = cv2.calcHist([image],[0], None, histSize, ranges)
hist3, bins = np.histogram(image, ranges_gap)

print("User 함수 : \n", hist1.flatten())
print("opencv 함수 : \n", hist2.flatten())
print("numpy 함수 : \n", hist3)
