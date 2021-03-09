@[TOC](目录)
# 1.题目
从一加到一亿（足够大），分别用一个进程、两个进程、四个进程、一个进程的两个线程、一个进程的四个线程来完成加法。使用多进程加的时候意味着每个进程加一部分，怎么把各个部分的数值合起来。并且对比五个结果是否相同、统计五个程序计算分别花了多少时间。
# 2.实验结论
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309235243579.png#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309235250353.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309235257788.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309235304504.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309235310776.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)

 总结：通过五个程序各执行三次，计算计算时间平均值，可以大致了解到最快的是四个进程的，最慢的是四个线程的。 

