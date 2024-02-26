@echo off

echo Version de Python instalada:
python --version

pip install pyfirmata
pip install cvzone
pip install opencv-python

echo.
echo Versión de pyfirmata:
python -c "import pyfirmata; print(pyfirmata.__version__)"

echo.
echo Versión de opencv-python:
python -c "import cv2; print(cv2.__version__)"

echo.
echo Instalacion completa!! :D
pause
