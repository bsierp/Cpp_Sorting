OBJ=./obj
FLAGS= -Wall -pedantic -std=c++2a -iquote inc
TRGDIR=./

# __start__: ${TRGDIR}/Sort
# 			${TRGDIR}/Sort
${TRGDIR}/Sort: ${OBJ}	${OBJ}/main.o ${OBJ}/Bucket.o ${OBJ}/Merge.o ${OBJ}/Quick.o ${OBJ}/Stack.o
			g++ -o ${TRGDIR}/Sort ${OBJ}/main.o ${OBJ}/Bucket.o ${OBJ}/Merge.o ${OBJ}/Quick.o ${OBJ}/Stack.o
${OBJ}:
			mkdir ${OBJ}
${OBJ}/main.o: src/main.cpp inc/Bucket.hh inc/Merge.hh inc/Quick.hh inc/Node.hh inc/rapidcsv.hh inc/Exception.hh inc/Stack.hh
			g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp
${OBJ}/Stack.o: src/Stack.cpp inc/Stack.hh inc/Node.hh
			g++ -c ${FLAGS} -o ${OBJ}/Stack.o src/Stack.cpp
${OBJ}/Merge.o: src/Merge.cpp inc/Merge.hh inc/Node.hh
			g++ -c ${FLAGS} -o ${OBJ}/Merge.o src/Merge.cpp
${OBJ}/Quick.o: src/Quick.cpp inc/Quick.hh inc/Node.hh
			g++ -c ${FLAGS} -o ${OBJ}/Quick.o src/Quick.cpp
${OBJ}/Bucket.o: src/Bucket.cpp inc/Bucket.hh inc/Stack.hh inc/Node.hh
			g++ -c ${FLAGS} -o ${OBJ}/Bucket.o src/Bucket.cpp
clear:
		rm -f ${OBJ}/*.o ${TRGDIR}/Sort