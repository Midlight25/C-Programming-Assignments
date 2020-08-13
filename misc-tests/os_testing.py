import os

desktop = os.path.join(os.environ.get('HOMEPATH'), "Desktop")

os.chdir(desktop)

print(os.getcwd())
