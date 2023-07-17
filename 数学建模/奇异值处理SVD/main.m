clear,clc; 
folder_name = 'D:\Desktop\新建文件夹\新建文件夹\第13讲.奇异值分解SVD和图形处理\代码和例题数据\葫芦娃七兄弟'; 
dirOutput=dir(fullfile(folder_name, '*.jpg'));  
%fullfile函数可根据指定的文件夹和文件名构建完整的文件路径。
%dir函数的作用: 返回指定路径的结构体类型的数组。数组中每一个元素以结构体类型存储着每个子文件的信息（文件名，创建时间等）。
files={dirOutput.name};  % 将数组中的文件名保存到一个元胞数组中
n = length(files);  % 图片的总数
ratio = 0.9;  % 要保留的特征比例为90%
for i = 1:n 
    disp('---------------------------------------------------------------------------------------------')
    photoname = files(i);   % 注意此时的photoname是一个cell字符串对象，需要转换为字符串
    % 如果我们直接把这个cell类型的变量，传递到其他函数中作为string类型使用，就会出现问题
    name = photoname{1};  %直接这样取第一个元素就可以啦~cell数组中取元素使用大括号
    photo_address = fullfile(folder_name, name);  %图片的绝对地址
    disp(photo_address)
    save_address = fullfile(folder_name, strcat('compress_',name));  % 压缩后文件的保存地址
    photo_compress(photo_address, save_address, ratio)
    disp('---------------------------------------------------------------------------------------------')
end