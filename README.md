# FileSize plugin for Avisynth
Since Avisynth can't get filesize using built-in function, then built FileSize plugin for get file's size by myself.

Usage:
```
filelegnth = FileSize("C:/Users/pakkapon/Downloads/Video/MyVideo.mp4")
```
Return:
```
file size in byte or -1 if file isn't exist.
```

Please note that return type is float to avoid integer overflow. 
but if you want return type in integer you can use Int() to convert Float to Int

Download:
[Prebuilt DLL and source](https://github.com/pureexe/FileSize_Avisynth/releases)
