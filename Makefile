OBJ=./obj
FLAGS= -Wall -pedantic -std=c++2a -iquote inc
TRGDIR=./

# __start__: ${TRGDIR}/Sort
# 			${TRGDIR}/Sort
${TRGDIR}/Sort: ${OBJ}	${OBJ}/main.o ${OBJ}/Bucket.o ${OBJ}/Merge.o ${OBJ}/Quick.o ${OBJ}/List.o
			g++ -o ${TRGDIR}/Sort ${OBJ}/main.o ${OBJ}/Bucket.o ${OBJ}/Merge.o ${OBJ}/Quick.o ${OBJ}/List.o
${OBJ}:
			mkdir ${OBJ}
${OBJ}/main.o: src/main.cpp inc/Bucket.hh inc/List.hh inc/Merge.hh inc/Quick.hh inc/Node.hh inc/rapidcsv.hh inc/Exception.hh
			g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp
${OBJ}/List.o: src/List.cpp inc/List.hh inc/Node.hh
			g++ -c ${FLAGS} -o ${OBJ}/List.o src/List.cpp
${OBJ}/Merge.o: src/Merge.cpp inc/Merge.hh inc/Node.hh
			g++ -c ${FLAGS} -o ${OBJ}/Merge.o src/Merge.cpp
${OBJ}/Quick.o: src/Quick.cpp inc/Quick.hh inc/Node.hh
			g++ -c ${FLAGS} -o ${OBJ}/Quick.o src/Quick.cpp
${OBJ}/Bucket.o: src/Bucket.cpp inc/Bucket.hh inc/List.hh inc/Node.hh
			g++ -c ${FLAGS} -o ${OBJ}/Bucket.o src/Bucket.cpp
clear:
		rm -f ${OBJ}/*.o ${TRGDIR}/Sort