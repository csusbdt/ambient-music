
a.out: *.cpp
	c++ *.cpp --std=c++11

kronos.wav: a.out
	./a.out kronos

.PHONY: mp3
mp3: kronos.wav
	ffmpeg                                       \
	-y -hide_banner                              \
	-i kronos.wav                                \
	-metadata title="Kronos"                     \
	-metadata artist="David Albert Turner"       \
	-metadata album_artist="David Albert Turner" \
	-metadata copyright="David Albert Turner"    \
	kronos.mp3

.PHONY: clean
clean:
	rm -f a.out
	rm -f kronos.wav
	rm -f kronos.mp3

