c++ main.cpp &&                                     \
./a.out &&                                          \
convert                                             \
	-depth 8 -size "1400x1400"                  \
	-pointsize 72                               \
	-fill "#ffffff"                             \
	-draw "text 200,320 'kronos 20m'"           \
	-pointsize 56                               \
	-draw "text 200,420 '2017-10-01 csusbdt'"  \
	out.rgb kronos20m.png

