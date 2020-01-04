from __future__ import unicode_literals
import youtube_dl
import os
import sys

def adapt():
    for i in os.listdir():
        if len(i.split()) >= 2:
            complete_name_list = i.split()
            complete_name_list[-1] = ".mp3"
            complete_name = complete_name_list[1] + complete_name_list[-1]
            os.rename(i, complete_name)
        else:
            print("No names to change")


def download(url, dw_path):
    download_options = {
    "format" : "bestaudio/best",
    "outtmpl" : "%(title)s.%(ext)s",
    "nocheckercertificate" : True,
    "postprocessors" : [{
        "key" : "FFmpegExtractAudio",
        "preferredcodec" : "mp3",
        "preferredquality" : "192"
    }],
}

    if not os.path.exists(dw_path):
        os.mkdir(dw_path)
        os.chdir(dw_path)
    else:
        os.chdir(dw_path)
    with youtube_dl.YoutubeDL(download_options) as dl:
        dl.download([url])

download(sys.argv[2], sys.argv[3])
a = input()