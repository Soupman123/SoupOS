@echo off
git add -A
set /p id="Enter Commit Message: "
git commit -m "%id%"
git push
pause