#!/bin/bash

# 프로젝트들이 있는 상위 디렉토리로 이동
cd /Users/taerin/Desktop/study/alice_git

# 각 프로젝트 디렉토리로 이동하여 git pull 수행
for dir in */ ; do
    echo "Updating $dir"
    cd "$dir"
    git pull
    cd ..
done
