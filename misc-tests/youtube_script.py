from pytube import YouTube
import os

os.chdir("C:\\Users\\micha\\Videos\\Captures")
print(os.getcwd())

yt = YouTube("https://www.youtube.com/watch?v=TOyPXNgBrU4")

for stream in yt.streams.all():
    print(stream)

yt.streams.first().download()
print("successful!")
