# Code Make
## This Section helps you write C++ files 
### PlotCodes:
##### input the plot name, x axis bin, x axis range in Plot_1D.txt
##### input the plot name, x axis bin, x axis range, y axis bin, yaxis bin in Plot2D.txt
##### You can add "END" in these txt files , the output files will have a blank line for the "END" lines in these txt files
##### then run : root -l -q Generate.cpp, it will generete 4 files
##### 1) headfile.txt : define the plots
##### 2) cppfile1.txt : allocate memory
##### 3) cppfile2.txt : specify error ()
##### 4) anafile.txt  : Fill the plots in the loop
##### note that all the txt files have space, in vim, you might want to use :set paste to avoid auto indent. Or you could change the output format in Generate.cpp

### Preselection:
##### input the variables name in initial.txt and initial2.txt (initial2 for array)
##### note that all array has max length defined in Generate.cpp, you might want to change them(line 88 - line 92)

### Preselection_trigger
##### Same as Preselection
