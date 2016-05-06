close all
clear all
imgMatColor = imread('C:\Kinju\kinjal10694\pictures\ab\amitabh-4441.jpg');
[rows, columns, numberOfColorChannels] = size(imgMatColor);
if numberOfColorChannels > 1
imgMat = rgb2gray(imgMatColor);
else
imgMat = imgMatColor;
end
imgMat = double(imgMat);
[U,S,V] = svd(imgMat);
i50 = U(:,1:50) * S(1:50,1:50) * V(:,1:50)';
i50 = uint8(i50);
i100 = U(:,1:100) * S(1:100,1:100) * V(:,1:100)';
i100 = uint8(i100);
i200 = U(:,1:200) * S(1:200,1:200) * V(:,1:200)';
i200 = uint8(i200);
subplot(2,2,1),imshow(uint8(imgMat));
title('Original Image');
subplot(2,2,2),imwrite(i50,'C:\Kinju\SEM 7\DCE\i50.jpg');
title('Image with 50x50 dimension');
subplot(2,2,3),imwrite(i100, 'C:\Kinju\SEM 7\DCE\i100.jpg');
title('Image with 100x100 dimension');
subplot(2,2,4),imwrite(i200, 'C:\Kinju\SEM 7\DCE\i200.jpg');
title('Image with 200x200 dimension');