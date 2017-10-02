c++ main.cpp &&                                     \
./a.out &&                                          \
convert                                             \
	-depth 8                                    \
	-size "1400x1400"                           \
	-gravity center                             \
	-fill "#ffffff"                             \
	-pointsize 32                               \
	-draw "text 0,-480 'csusbdt'"               \
	-pointsize 56                               \
	-draw "text 0,-400 'David Turner'"          \
	-pointsize 86                               \
	-draw "text 0,-280 'Kronos'"                \
	-pointsize 62                               \
	-draw "text 0,280 '20m'"                    \
	-pointsize 40                               \
	-draw "text 0,400 '2017-10-01'"             \
	-pointsize 32                               \
	-draw "text 0,490 'Listen attentively to fall asleep or play as'"  \
	-draw "text 0,530 'peaceful background music to focus on work.'"   \
	out.rgb kronos20m.png

convert                                      \
	-size 975x180                        \
	-gravity center                      \
	-fill "#ffffff"                      \
	-pointsize 56                        \
	-draw "text -240,0 'David Turner'"   \
	-pointsize 32                        \
	-draw "text  240,0 'csusbdt'"        \
	xc:#00ff00                           \
	header.png

x	xc:white                             \
#	-pointsize 56                               \
#	-draw "text 200,260 'David Turner'"         \
#	-pointsize 86                               \
#	-draw "text 200,420 'Kronos'"               \
#	-pointsize 62                               \
#	-draw "text 520,420 '20m'"                  \
#	-pointsize 48                               \
#	-draw "text 200,700 'csusbdt'"              \
#	-pointsize 40                               \
#	-draw "text 200,754 '2017-10-01'"           \
#	-draw "text 200,478 '2017-10-01'"           \
