from PyQt4.uic import loadUiType
#import matplotlib.pyplot as plt
from matplotlib.figure import Figure
from matplotlib.backends.backend_qt4agg import (
    FigureCanvasQTAgg as FigureCanvas,
    NavigationToolbar2QT as NavigationToolbar)
import numpy as np

Ui_MainWindow, QMainWindow = loadUiType('test.ui')


class Main(QMainWindow, Ui_MainWindow):
    fig = Figure()
    plot = fig.add_subplot(111)
     
    def __init__(self, *argv):
        super(Main, self).__init__()
        self.setupUi(self)

        self.TabPot.setTabText(0,"Infinite")
        self.TabPot.setTabText(1,"Finite")
        self.TabPot.setTabText(2,"Harmonic")

        self.TabPot.currentChanged.connect(self.TabChanged)
        
        self.canvas = FigureCanvas(self.fig)
        self.MainGrid.addWidget(self.canvas)
        self.UpdatePlot("Infinite")
        
        self.WidthSpinBoxInfinite.valueChanged.connect(self.UpdateWidthSpinBox)
        self.WidthSliderInfinite.valueChanged.connect(self.UpdateWidthSlider)


    def TabChanged(self, index):
        self.UpdatePlot(self.TabPot.tabText(index))
        print(index)
        
    def UpdatePlot(self, potential):
        self.plot.clear()
        
        if potential == "Infinite":
            a = self.WidthSpinBoxInfinite.value()
            self.x = np.arange(-a/2,a/2, a/100)
            self.plot.fill_between([-a-5,-a/2,-a/2+0.01,a/2+0.01,a/2,a+5], [6,6,0,0,6,6], facecolor='black')
            self.plot.fill_between([-a-5,a+5], [-1]*2, facecolor="black")
            
            for i in range(3):
                self.plot.plot(self.x, 2*i-1 + np.sqrt(2/a)*np.sin(i*2*np.pi/a*self.x), color="black")
                self.plot.plot(self.x,2*i + np.sqrt(2/a)*np.cos((2*i+1)*np.pi/a*self.x), color="black")

            self.plot.set_xlim([-(a+1),a+1])
            self.plot.set_ylim([-0.5,5])
            
        if potential == "Finite":
            """
            a = self.WidthSpinBoxFinite.value()
            m = self.MassSpinBoxFinite.value()
            V = self.DepthSpinBoxFinite.value()
            
            self.x = np.arange(-a/2, a/2, a/100)
            modes = finite.finite(a, V, m)

            self.plot.fill_between([-a-5,-a/2,-a/2+0.01,a/2+0.01,a/2,a+5], [V,V,0,0,V,V], facecolor='black')
            self.plot.fill_between([-a-5,a+5], [-1]*2, facecolor="black")
            
            for i in modes:
                self.plot.plot(self.x,

            self.plot.set_xlim([-(a+6),a+6])
            self.plot.set_ylim([-0.5,1.1*V])
            """
            pass
            
        self.plot.set_xlabel("X-Coordinate")
        self.plot.set_ylabel("Wavefunction")
        self.canvas.draw()

    def UpdateWidthSpinBox(self):
        a = self.WidthSpinBoxInfinite.value()
        self.WidthSliderInfinite.setValue(a)
        self.UpdatePlot("Infinite")
        
    def UpdateWidthSlider(self):
        a = self.WidthSliderInfinite.value()
        self.WidthSpinBoxInfinite.setValue(a)

    
if __name__ == '__main__':
    import sys
    from PyQt4 import QtGui
      
    app = QtGui.QApplication(sys.argv)
    main= Main()

    main.show()
    sys.exit(app.exec_())
