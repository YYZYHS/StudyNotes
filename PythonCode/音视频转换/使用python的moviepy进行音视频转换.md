使用python的moviepy，这个可以快速的将视频中音频提取出来。
亲自测试，将一个两个小时的视频转成音频，只需要 两分钟 左右；提取出来的音频大小为120M左右，格式为mp3。
不建议使用wav，这个是无损的，导致生成的音频文件巨大。

具体使用如下：
```python
# 先导入相关类

from moviepy.editor import VideoFileClip

# 然后开始转换

video = VideoFileClip('关雎.mp4') # 这里写入你的视频文件名

audio = video.audio              # 这里是提取的音频

audio.write_audiofile('关雎.mp3') # 这里写入你的音频文件名
```
当然了，我们首先需要安装moviepy
`pip install moviepy`
如果下载过慢，可以使用豆瓣源。
`pip install moviepy -i https://mirrors.aliyun.com/pypi/simple/`
