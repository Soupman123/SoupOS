git add -A
@echo off
set /p id="Enter Commit Message: "
git commit -m "%id%"
git push