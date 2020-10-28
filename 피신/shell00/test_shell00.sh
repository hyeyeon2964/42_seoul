cd ex00
echo ---- testing ex00 ----
echo -e "실행 : cat z \n-------- \n"
cat z
cd ..
cd ex01
echo -e "\n---- testing ex01 ----"
echo -e "압축해제 후 ls -l 실행\n-------- \n"
tar -xf testShell00.tar
mv testShell00.tar ..
ls -l
mv ../testShell00.tar .
chmod 777 testShell00
rm testShell00
cd ..
cd ex02
echo -e "\n---- testing ex02 ----"
tar -xf exo2.tar
echo -e "압축해제 후 ls -l 실행\n--------- \n"
mv exo2.tar ..
ls -l
mv ../exo2.tar .
chmod 777 test*
rm -r test*
cd ../ex03
echo -e "\n---- testing ex03 ----"
echo -e "klist.txt 파일 출력\n-------- \n"
cat klist.txt
​
cd ../ex04
echo -e "\n---- testing ex04 ----\n파일 적절히 생성후 midLS 파일 실행\n----------\n"
touch t_first t_second t_third
mkdir t_something_folder
cd t_something_folder
touch t_yes t_no
cd ..
touch t_oldest
touch -t 201012311200 t_oldest
touch -t 205012211200 t_newest
bash midLS
# ls -l
rm -r t_*
​
cd ../ex05
echo -e "\n---- testing ex05 ----\n실행: bash git_commit.sh | cat -e\n----------\n"
bash git_commit.sh | cat -e
​
echo -e "\n------비교바람(아래는 git log | cat 의 결과)------\n"
git log | cat
​
cd ../ex06
ex06_gitignore="tg_a\ntg_b\ntg_c"
echo -e "\n--- testing ex06 ----\n.gitignore 파일 생성 및 적절한 파일 생성후 bash git_ignore.sh | cat -e 실행\n.gitignore 파일 내용: $ex06_gitignore\n------------\n"
cd ..
echo -e $ex06_gitignore > .gitignore
cd ex06
touch tg_a tg_b
mkdir tg_c
cd tg_c
touch tg_d tg_e
cd ..
bash git_ignore.sh | cat -e
cd ..
rm .gitignore
cd ex06
rm -r tg_*
ls
​
​
cd ../ex07
echo -e "\n--- testing ex07 ----\nb 파일 출력\n-------\n"
cat -e b
​
cd ..
cd ex08
echo -e "\n--- testing ex08 ----\n 파일 생성\n-------\n이전:\n"
touch t_normal "t_some~" "t_some#" "#t_some#"
mkdir t_f
cd t_f
touch "#t_dumb#" "~t_dumb~"
cd ..
find .
​
echo -e "\n-------\n/bin/sh clean 실행\n-------\n"
/bin/sh clean
​
echo -e "\n---이후---\n"
find .
​
rm -r *t_*
ls
​
​
cd ..
cd ex09
​
echo -e "\n--- testing ex09 --- \n적절한 파일 생성, 매직 파일 컴파일 후 적용\n-------\n"
file -C -m ft_magic
echo 0000000000111111111122222222223333333333442 > something
file -m ft_magic *
rm *.mgc something
cd ..

