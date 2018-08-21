import os,sys,inspect
current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from build import display

d = display.Display(300, 300, "Test")
while d.isWindowOpen():
    d.update()
    d.clear(0.0, 1.0, 0.0, 1.0)
    pass