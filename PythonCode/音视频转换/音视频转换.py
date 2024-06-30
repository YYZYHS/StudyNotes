# 先导入相关类
from moviepy.editor import VideoFileClip
# 然后开始转换
video = VideoFileClip('关雎.mp4') # 这里写入你的视频文件名
audio = video.audio              # 这里是提取的音频
audio.write_audiofile('关雎.mp3') # 这里写入你的音频文件名
