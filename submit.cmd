@echo off
color 0a
title SoupOS submit
echo Adding Files to commit.
git add --all
git reset -- submit.cmd
git reset -- submit.cmd.lnk
git reset -- Resources/*
git status
set /p id=Enter Commit Message: 
echo %id%
git commit -m "%id%"
echo Are you sure you want to push? Press any key to continue...
pause >nul
git push
echo Done.
pause>nul|set/p =any key to exit ...