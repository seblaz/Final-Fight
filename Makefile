format:

	find src/ -name "**.cpp' -exec indent {} \;
	find src/ -name '**.c' -exec indent {} \;
	find src/ -name '**.h' -exec indent {} \;

sdl2:
	sudo apt install -f libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
    
xerces:
	cd /tmp && \
	curl -sL http://ftp.cixug.es/apache//xerces/c/3/sources/xerces-c-3.2.2.tar.gz | tar xvz && \
	cd xerces-c-3.2.2 && \
	./configure && \
	make && \
	sudo make install && \
	rm -rf xerces-c-3.2.2

valgrind:
	apt install valgrind

dbg:
	sudo apt install -f libstdc++6-8-dbg

dep:	sdl2	xerces	dbg

clean:
	find . -type f -name "*~" -exec rm -f {} \;
