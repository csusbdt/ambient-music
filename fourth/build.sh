c++ *.cpp --std=c++11  && \
./a.out | ffmpeg -y -hide_banner -f s16le -ar 48000 -ac 1 -i - kronos.mp3

