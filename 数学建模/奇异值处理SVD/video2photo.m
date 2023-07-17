%% 读取视频
% video_file='新闻联播.flv';
video_file='D:\Desktop\新建文件夹\新建文件夹\第13讲.奇异值分解SVD和图形处理\代码和例题数据\迅捷视频转换器转换后的新闻联播.mp4';
video=VideoReader(video_file);  
frame_number = video.NumberOfFrames; %视频的总帧数
%512帧
%% 分离图片
for i=1:30:frame_number   % 这里演示的是每30帧数保存一次（如果每一帧都全部保存的话所要花费的时间很长）
    image_name=strcat('D:\Desktop\新建文件夹\新建文件夹\第13讲.奇异值分解SVD和图形处理\代码和例题数据\image_',num2str(i),'.jpg');
% % 自己运行时路径一定要改成自己电脑上文件夹的路径，别直接用我的路径就运行了，可能会报错的。
    Photo=read(video,i);            %读出所在帧的图片对象
    imwrite(Photo,image_name);      %将图片保存到指定的位置
end

% 注意：Matlab对视频的要求较高，如果出现下面的错误，则需要先将视频进行解码
% 我使用的是迅捷视频转换器
% 错误使用 VideoReader/init (line 619)
% 无法确定所需的编解码器。
% video中的对象讲解：https://blog.csdn.net/marleylee/article/details/77770860