#/bin/bash

#git config --global user.name "MayXD"
#git config --global user.email 1096may1559629925@gmail.com

commit_dir=$(pwd)/*
commit_info=$1
git add "$commit_dir"
git commit -m "$commit_info"
git push origin master
