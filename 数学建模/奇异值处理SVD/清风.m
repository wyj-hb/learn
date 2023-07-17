clear,clc; 
photo_compress('D:\Desktop\新建文件夹\新建文件夹\第13讲.奇异值分解SVD和图形处理\代码和例题数据\奇异值分解SVD用于单张图片压缩\赫本.jpg',  'D:\Desktop\新建文件夹\新建文件夹\第13讲.奇异值分解SVD和图形处理\代码和例题数据\奇异值分解SVD用于单张图片压缩\compress_赫本1.jpg',  0.5);
photo_compress('赫本.jpg',  'compress_赫本2.jpg',  0.7);
photo_compress('赫本.jpg',  'compress_赫本3.jpg',  0.9);
photo_compress('千与千寻.jpg', 'compress_千与千寻.jpg', 0.8) ;
photo_compress('千与千寻.jpg', 'compress_gray_千与千寻.jpg', 0.8, 1); % 先转换为灰色图片后再压缩 