

default:	build



build:	build-influxdb-cxx



build-influxdb-cxx:
	@echo "";							\
	echo "========================================";		\
	echo "    make $@";						\
	echo "========================================";

	cd influxdb-cxx;						\
	if [ ! -d 'build' ];						\
	then								\
		mkdir 'build';						\
	fi;								\
									\
	cd 'build';							\
	cmake -D INFLUXCXX_TESTING:BOOL=OFF ..;				\
	make
