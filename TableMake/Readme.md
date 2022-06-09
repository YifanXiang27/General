# Table Make
## This part have strict output requirement. See data.txt for the format or example
### If you use the Loop in General, it will generate data_.txt automatically, which is exactly same as the requirement of this part.
### When you finish the loop, (be careful! delete all the data*.txt before you run the loop) and copy the data.txt to this directory
### Running example:
      ##############################
      cp {???/data.txt} .
      sh run.sh
      root -l -q Calculate.cpp
      ##############################
### Here is some description on how this works:
      The data.txt will have SAMPLENAME as the trigger for the code to read the next string as the sample name
      In Calculate.cpp, it will read all the samples in data.txt and group it (you can define the group in groupinformation.txt. will talk about it later)
      If you want to look at it in linux terminal, open linuxtable.txt or linuxtable_group.txt. The latter shows the group cut flow
      If you want to output it into an excel table, in excel app, open exceltable.txt or exceltable_group.txt. The latter shows the group cut flow. and choose ',' as delimiter.
      If you want to have error to be another line, use the one with "detailed" tag
### define groupinformation.txt :      
      The format is : 
      {Groupname}   {samplename1} {samplename2} {samplename3} {...} END
      with {} you need to change the name. You can find some example in the directory.
