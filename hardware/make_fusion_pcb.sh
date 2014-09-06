#!/bin/sh

PROJ=tinymac
DIR=${PROJ}_fusion
ZIP_FILE=${PROJ}_gerber.zip

if [ -d ${DIR} ]; then
	rm -R ${DIR}
fi

mkdir ${DIR}

cp ${PROJ}.GTL ${DIR}/
cp ${PROJ}.GBL ${DIR}/
cp ${PROJ}.GTS ${DIR}/
cp ${PROJ}.GBS ${DIR}/
cp ${PROJ}.GTO ${DIR}/
cp ${PROJ}.GBO ${DIR}/
cp ${PROJ}.TXT ${DIR}/
cp ${PROJ}.GML ${DIR}/

zip ${ZIP_FILE} ${DIR}/*

rm -R ${DIR}


