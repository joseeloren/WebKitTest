default: WebKit2Test

FLAGS=`pkg-config webkit2gtk-4.0 javascriptcoregtk-4.0 --cflags --libs`

WebKit2Test: WebKit2Test.cpp
	gcc $< $(FLAGS) -g -o $@

clean:
	-rm -f WebKit2Test
