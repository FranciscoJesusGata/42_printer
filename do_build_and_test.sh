# This is a script to build and run the the pft_2019 (https://github.com/cclaude42/PFT_2019) (could be use for the normal pft(https://github.com/gavinfielder/pft.git))
# Script created by fgata-va (Github: https://github.com/FranciscoJesusGata)
make re
make clean
make -C pft_2019
./pft_2019/test $1
cat results.txt
rm -f history.csv test.libc test.mine
