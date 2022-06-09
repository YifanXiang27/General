rm data*.txt
rm output*.out
rm *.root
make clean
make -j
./Task.exe List_Preskim/Filelist_SSWW2016APV.list SSWW2016APV SSWW2016APV > output_SSWW2016APV.out &
./Task.exe List_Preskim/Filelist_SSWW2016.list SSWW2016 SSWW2016 > output_SSWW2016.out &
./Task.exe List_Preskim/Filelist_SSWW2017.list SSWW2017 SSWW2017 > output_SSWW2017.out &
./Task.exe List_Preskim/Filelist_SSWW2018.list SSWW2018 SSWW2018 > output_SSWW2018.out &
./Task.exe List_Preskim/Filelist_TTTo2L2Nu2016APV.list TTTo2L2Nu2016APV TTTo2L2Nu2016APV > output_TTTo2L2Nu2016APV.out &
./Task.exe List_Preskim/Filelist_TTTo2L2Nu2016.list TTTo2L2Nu2016 TTTo2L2Nu2016 > output_TTTo2L2Nu2016.out &
./Task.exe List_Preskim/Filelist_TTTo2L2Nu2017.list TTTo2L2Nu2017 TTTo2L2Nu2017 > output_TTTo2L2Nu2017.out &
./Task.exe List_Preskim/Filelist_TTTo2L2Nu2018.list TTTo2L2Nu2018 TTTo2L2Nu2018 > output_TTTo2L2Nu2018.out &
./Task.exe List_Preskim/Filelist_TTToSemiLeptonic2016APV.list TTToSemiLeptonic2016APV TTToSemiLeptonic2016APV > output_TTToSemiLeptonic2016APV.out &
./Task.exe List_Preskim/Filelist_TTToSemiLeptonic2016.list TTToSemiLeptonic2016 TTToSemiLeptonic2016 > output_TTToSemiLeptonic2016.out &
sleep 1m
./Task.exe List_Preskim/Filelist_TTToSemiLeptonic2017.list TTToSemiLeptonic2017 TTToSemiLeptonic2017 > output_TTToSemiLeptonic2017.out &
./Task.exe List_Preskim/Filelist_TTToSemiLeptonic2018.list TTToSemiLeptonic2018 TTToSemiLeptonic2018 > output_TTToSemiLeptonic2018.out &
./Task.exe List_Preskim/Filelist_TTWJetsToLNu2016APV.list TTWJetsToLNu2016APV TTWJetsToLNu2016APV > output_TTWJetsToLNu2016APV.out &
./Task.exe List_Preskim/Filelist_TTWJetsToLNu2016.list TTWJetsToLNu2016 TTWJetsToLNu2016 > output_TTWJetsToLNu2016.out &
./Task.exe List_Preskim/Filelist_TTWJetsToLNu2017.list TTWJetsToLNu2017 TTWJetsToLNu2017 > output_TTWJetsToLNu2017.out &
./Task.exe List_Preskim/Filelist_TTWJetsToLNu2018.list TTWJetsToLNu2018 TTWJetsToLNu2018 > output_TTWJetsToLNu2018.out &
./Task.exe List_Preskim/Filelist_TTWW2016APV.list TTWW2016APV TTWW2016APV > output_TTWW2016APV.out &
./Task.exe List_Preskim/Filelist_TTWW2016.list TTWW2016 TTWW2016 > output_TTWW2016.out &
./Task.exe List_Preskim/Filelist_TTWW2017.list TTWW2017 TTWW2017 > output_TTWW2017.out &
./Task.exe List_Preskim/Filelist_TTWW2018.list TTWW2018 TTWW2018 > output_TTWW2018.out &
sleep 1m
./Task.exe List_Preskim/Filelist_TTWZ2016APV.list TTWZ2016APV TTWZ2016APV > output_TTWZ2016APV.out &
./Task.exe List_Preskim/Filelist_TTWZ2016.list TTWZ2016 TTWZ2016 > output_TTWZ2016.out &
./Task.exe List_Preskim/Filelist_TTWZ2017.list TTWZ2017 TTWZ2017 > output_TTWZ2017.out &
./Task.exe List_Preskim/Filelist_TTWZ2018.list TTWZ2018 TTWZ2018 > output_TTWZ2018.out &
./Task.exe List_Preskim/Filelist_TTZToLLNuNu_M-102016APV.list TTZToLLNuNu_M-102016APV TTZToLLNuNu_M-102016APV > output_TTZToLLNuNu_M-102016APV.out &
./Task.exe List_Preskim/Filelist_TTZToLLNuNu_M-102016.list TTZToLLNuNu_M-102016 TTZToLLNuNu_M-102016 > output_TTZToLLNuNu_M-102016.out &
./Task.exe List_Preskim/Filelist_TTZToLLNuNu_M-102017.list TTZToLLNuNu_M-102017 TTZToLLNuNu_M-102017 > output_TTZToLLNuNu_M-102017.out &
./Task.exe List_Preskim/Filelist_TTZToLLNuNu_M-102018.list TTZToLLNuNu_M-102018 TTZToLLNuNu_M-102018 > output_TTZToLLNuNu_M-102018.out &
./Task.exe List_Preskim/Filelist_TTbb_4f_TTTo2L2Nu2016APV.list TTbb_4f_TTTo2L2Nu2016APV TTbb_4f_TTTo2L2Nu2016APV > output_TTbb_4f_TTTo2L2Nu2016APV.out &
./Task.exe List_Preskim/Filelist_TTbb_4f_TTTo2L2Nu2016.list TTbb_4f_TTTo2L2Nu2016 TTbb_4f_TTTo2L2Nu2016 > output_TTbb_4f_TTTo2L2Nu2016.out &
sleep 1m
./Task.exe List_Preskim/Filelist_TTbb_4f_TTTo2L2Nu2017.list TTbb_4f_TTTo2L2Nu2017 TTbb_4f_TTTo2L2Nu2017 > output_TTbb_4f_TTTo2L2Nu2017.out &
./Task.exe List_Preskim/Filelist_TTbb_4f_TTTo2L2Nu2018.list TTbb_4f_TTTo2L2Nu2018 TTbb_4f_TTTo2L2Nu2018 > output_TTbb_4f_TTTo2L2Nu2018.out &
./Task.exe List_Preskim/Filelist_TTbb_4f_TTToSemiLeptonic2016APV.list TTbb_4f_TTToSemiLeptonic2016APV TTbb_4f_TTToSemiLeptonic2016APV > output_TTbb_4f_TTToSemiLeptonic2016APV.out &
./Task.exe List_Preskim/Filelist_TTbb_4f_TTToSemiLeptonic2016.list TTbb_4f_TTToSemiLeptonic2016 TTbb_4f_TTToSemiLeptonic2016 > output_TTbb_4f_TTToSemiLeptonic2016.out &
./Task.exe List_Preskim/Filelist_TTbb_4f_TTToSemiLeptonic2017.list TTbb_4f_TTToSemiLeptonic2017 TTbb_4f_TTToSemiLeptonic2017 > output_TTbb_4f_TTToSemiLeptonic2017.out &
./Task.exe List_Preskim/Filelist_TTbb_4f_TTToSemiLeptonic2018.list TTbb_4f_TTToSemiLeptonic2018 TTbb_4f_TTToSemiLeptonic2018 > output_TTbb_4f_TTToSemiLeptonic2018.out &
./Task.exe List_Preskim/Filelist_VHToNonbb_M1252016APV.list VHToNonbb_M1252016APV VHToNonbb_M1252016APV > output_VHToNonbb_M1252016APV.out &
./Task.exe List_Preskim/Filelist_VHToNonbb_M1252016.list VHToNonbb_M1252016 VHToNonbb_M1252016 > output_VHToNonbb_M1252016.out &
./Task.exe List_Preskim/Filelist_VHToNonbb_M1252017.list VHToNonbb_M1252017 VHToNonbb_M1252017 > output_VHToNonbb_M1252017.out &
./Task.exe List_Preskim/Filelist_VHToNonbb_M1252018.list VHToNonbb_M1252018 VHToNonbb_M1252018 > output_VHToNonbb_M1252018.out &
sleep 1m
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-100To2002016APV.list WJetsToLNu_HT-100To2002016APV WJetsToLNu_HT-100To2002016APV > output_WJetsToLNu_HT-100To2002016APV.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-100To2002016.list WJetsToLNu_HT-100To2002016 WJetsToLNu_HT-100To2002016 > output_WJetsToLNu_HT-100To2002016.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-100To2002017.list WJetsToLNu_HT-100To2002017 WJetsToLNu_HT-100To2002017 > output_WJetsToLNu_HT-100To2002017.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-100To2002018.list WJetsToLNu_HT-100To2002018 WJetsToLNu_HT-100To2002018 > output_WJetsToLNu_HT-100To2002018.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-1200To25002016APV.list WJetsToLNu_HT-1200To25002016APV WJetsToLNu_HT-1200To25002016APV > output_WJetsToLNu_HT-1200To25002016APV.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-1200To25002016.list WJetsToLNu_HT-1200To25002016 WJetsToLNu_HT-1200To25002016 > output_WJetsToLNu_HT-1200To25002016.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-1200To25002017.list WJetsToLNu_HT-1200To25002017 WJetsToLNu_HT-1200To25002017 > output_WJetsToLNu_HT-1200To25002017.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-1200To25002018.list WJetsToLNu_HT-1200To25002018 WJetsToLNu_HT-1200To25002018 > output_WJetsToLNu_HT-1200To25002018.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-200To4002016APV.list WJetsToLNu_HT-200To4002016APV WJetsToLNu_HT-200To4002016APV > output_WJetsToLNu_HT-200To4002016APV.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-200To4002016.list WJetsToLNu_HT-200To4002016 WJetsToLNu_HT-200To4002016 > output_WJetsToLNu_HT-200To4002016.out &
sleep 1m
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-200To4002017.list WJetsToLNu_HT-200To4002017 WJetsToLNu_HT-200To4002017 > output_WJetsToLNu_HT-200To4002017.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-200To4002018.list WJetsToLNu_HT-200To4002018 WJetsToLNu_HT-200To4002018 > output_WJetsToLNu_HT-200To4002018.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-2500ToInf2016APV.list WJetsToLNu_HT-2500ToInf2016APV WJetsToLNu_HT-2500ToInf2016APV > output_WJetsToLNu_HT-2500ToInf2016APV.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-2500ToInf2016.list WJetsToLNu_HT-2500ToInf2016 WJetsToLNu_HT-2500ToInf2016 > output_WJetsToLNu_HT-2500ToInf2016.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-2500ToInf2017.list WJetsToLNu_HT-2500ToInf2017 WJetsToLNu_HT-2500ToInf2017 > output_WJetsToLNu_HT-2500ToInf2017.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-2500ToInf2018.list WJetsToLNu_HT-2500ToInf2018 WJetsToLNu_HT-2500ToInf2018 > output_WJetsToLNu_HT-2500ToInf2018.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-400To6002016APV.list WJetsToLNu_HT-400To6002016APV WJetsToLNu_HT-400To6002016APV > output_WJetsToLNu_HT-400To6002016APV.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-400To6002016.list WJetsToLNu_HT-400To6002016 WJetsToLNu_HT-400To6002016 > output_WJetsToLNu_HT-400To6002016.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-400To6002017.list WJetsToLNu_HT-400To6002017 WJetsToLNu_HT-400To6002017 > output_WJetsToLNu_HT-400To6002017.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-400To6002018.list WJetsToLNu_HT-400To6002018 WJetsToLNu_HT-400To6002018 > output_WJetsToLNu_HT-400To6002018.out &
sleep 1m
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-600To8002016APV.list WJetsToLNu_HT-600To8002016APV WJetsToLNu_HT-600To8002016APV > output_WJetsToLNu_HT-600To8002016APV.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-600To8002016.list WJetsToLNu_HT-600To8002016 WJetsToLNu_HT-600To8002016 > output_WJetsToLNu_HT-600To8002016.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-600To8002017.list WJetsToLNu_HT-600To8002017 WJetsToLNu_HT-600To8002017 > output_WJetsToLNu_HT-600To8002017.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-600To8002018.list WJetsToLNu_HT-600To8002018 WJetsToLNu_HT-600To8002018 > output_WJetsToLNu_HT-600To8002018.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-70To1002016APV.list WJetsToLNu_HT-70To1002016APV WJetsToLNu_HT-70To1002016APV > output_WJetsToLNu_HT-70To1002016APV.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-70To1002016.list WJetsToLNu_HT-70To1002016 WJetsToLNu_HT-70To1002016 > output_WJetsToLNu_HT-70To1002016.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-70To1002017.list WJetsToLNu_HT-70To1002017 WJetsToLNu_HT-70To1002017 > output_WJetsToLNu_HT-70To1002017.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-70To1002018.list WJetsToLNu_HT-70To1002018 WJetsToLNu_HT-70To1002018 > output_WJetsToLNu_HT-70To1002018.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-800To12002016APV.list WJetsToLNu_HT-800To12002016APV WJetsToLNu_HT-800To12002016APV > output_WJetsToLNu_HT-800To12002016APV.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-800To12002016.list WJetsToLNu_HT-800To12002016 WJetsToLNu_HT-800To12002016 > output_WJetsToLNu_HT-800To12002016.out &
sleep 1m
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-800To12002017.list WJetsToLNu_HT-800To12002017 WJetsToLNu_HT-800To12002017 > output_WJetsToLNu_HT-800To12002017.out &
./Task.exe List_Preskim/Filelist_WJetsToLNu_HT-800To12002018.list WJetsToLNu_HT-800To12002018 WJetsToLNu_HT-800To12002018 > output_WJetsToLNu_HT-800To12002018.out &
./Task.exe List_Preskim/Filelist_WWW_4F2016APV.list WWW_4F2016APV WWW_4F2016APV > output_WWW_4F2016APV.out &
./Task.exe List_Preskim/Filelist_WWW_4F2016.list WWW_4F2016 WWW_4F2016 > output_WWW_4F2016.out &
./Task.exe List_Preskim/Filelist_WWW_4F2017.list WWW_4F2017 WWW_4F2017 > output_WWW_4F2017.out &
./Task.exe List_Preskim/Filelist_WWW_4F2018.list WWW_4F2018 WWW_4F2018 > output_WWW_4F2018.out &
./Task.exe List_Preskim/Filelist_WWZ_4F2016APV.list WWZ_4F2016APV WWZ_4F2016APV > output_WWZ_4F2016APV.out &
./Task.exe List_Preskim/Filelist_WWZ_4F2016.list WWZ_4F2016 WWZ_4F2016 > output_WWZ_4F2016.out &
./Task.exe List_Preskim/Filelist_WWZ_4F2017.list WWZ_4F2017 WWZ_4F2017 > output_WWZ_4F2017.out &
./Task.exe List_Preskim/Filelist_WWZ_4F2018.list WWZ_4F2018 WWZ_4F2018 > output_WWZ_4F2018.out &
sleep 1m
./Task.exe List_Preskim/Filelist_WZJJ_EWK_InclusivePolarization2016APV.list WZJJ_EWK_InclusivePolarization2016APV WZJJ_EWK_InclusivePolarization2016APV > output_WZJJ_EWK_InclusivePolarization2016APV.out &
./Task.exe List_Preskim/Filelist_WZJJ_EWK_InclusivePolarization2016.list WZJJ_EWK_InclusivePolarization2016 WZJJ_EWK_InclusivePolarization2016 > output_WZJJ_EWK_InclusivePolarization2016.out &
./Task.exe List_Preskim/Filelist_WZJJ_EWK_InclusivePolarization2017.list WZJJ_EWK_InclusivePolarization2017 WZJJ_EWK_InclusivePolarization2017 > output_WZJJ_EWK_InclusivePolarization2017.out &
./Task.exe List_Preskim/Filelist_WZJJ_EWK_InclusivePolarization2018.list WZJJ_EWK_InclusivePolarization2018 WZJJ_EWK_InclusivePolarization2018 > output_WZJJ_EWK_InclusivePolarization2018.out &
./Task.exe List_Preskim/Filelist_WZTo3LNu2016APV.list WZTo3LNu2016APV WZTo3LNu2016APV > output_WZTo3LNu2016APV.out &
./Task.exe List_Preskim/Filelist_WZTo3LNu2016.list WZTo3LNu2016 WZTo3LNu2016 > output_WZTo3LNu2016.out &
./Task.exe List_Preskim/Filelist_WZTo3LNu2017.list WZTo3LNu2017 WZTo3LNu2017 > output_WZTo3LNu2017.out &
./Task.exe List_Preskim/Filelist_WZTo3LNu2018.list WZTo3LNu2018 WZTo3LNu2018 > output_WZTo3LNu2018.out &
./Task.exe List_Preskim/Filelist_WZZ2016APV.list WZZ2016APV WZZ2016APV > output_WZZ2016APV.out &
./Task.exe List_Preskim/Filelist_WZZ2016.list WZZ2016 WZZ2016 > output_WZZ2016.out &
sleep 1m
./Task.exe List_Preskim/Filelist_WZZ2017.list WZZ2017 WZZ2017 > output_WZZ2017.out &
./Task.exe List_Preskim/Filelist_WZZ2018.list WZZ2018 WZZ2018 > output_WZZ2018.out &
./Task.exe List_Preskim/Filelist_WZ2016APV.list WZ2016APV WZ2016APV > output_WZ2016APV.out &
./Task.exe List_Preskim/Filelist_WZ2016.list WZ2016 WZ2016 > output_WZ2016.out &
./Task.exe List_Preskim/Filelist_WZ2017.list WZ2017 WZ2017 > output_WZ2017.out &
./Task.exe List_Preskim/Filelist_WZ2018.list WZ2018 WZ2018 > output_WZ2018.out &
./Task.exe List_Preskim/Filelist_ZZTo4L_M-1toInf2016APV.list ZZTo4L_M-1toInf2016APV ZZTo4L_M-1toInf2016APV > output_ZZTo4L_M-1toInf2016APV.out &
./Task.exe List_Preskim/Filelist_ZZTo4L_M-1toInf2016.list ZZTo4L_M-1toInf2016 ZZTo4L_M-1toInf2016 > output_ZZTo4L_M-1toInf2016.out &
./Task.exe List_Preskim/Filelist_ZZTo4L_M-1toInf2017.list ZZTo4L_M-1toInf2017 ZZTo4L_M-1toInf2017 > output_ZZTo4L_M-1toInf2017.out &
./Task.exe List_Preskim/Filelist_ZZTo4L_M-1toInf2018.list ZZTo4L_M-1toInf2018 ZZTo4L_M-1toInf2018 > output_ZZTo4L_M-1toInf2018.out &
sleep 1m
./Task.exe List_Preskim/Filelist_ZZZ2016APV.list ZZZ2016APV ZZZ2016APV > output_ZZZ2016APV.out &
./Task.exe List_Preskim/Filelist_ZZZ2016.list ZZZ2016 ZZZ2016 > output_ZZZ2016.out &
./Task.exe List_Preskim/Filelist_ZZZ2017.list ZZZ2017 ZZZ2017 > output_ZZZ2017.out &
./Task.exe List_Preskim/Filelist_ZZZ2018.list ZZZ2018 ZZZ2018 > output_ZZZ2018.out &
./Task.exe List_Preskim/Filelist_ttHToNonbb_M1252016APV.list ttHToNonbb_M1252016APV ttHToNonbb_M1252016APV > output_ttHToNonbb_M1252016APV.out &
./Task.exe List_Preskim/Filelist_ttHToNonbb_M1252016.list ttHToNonbb_M1252016 ttHToNonbb_M1252016 > output_ttHToNonbb_M1252016.out &
./Task.exe List_Preskim/Filelist_ttHToNonbb_M1252017.list ttHToNonbb_M1252017 ttHToNonbb_M1252017 > output_ttHToNonbb_M1252017.out &
./Task.exe List_Preskim/Filelist_ttHToNonbb_M1252018.list ttHToNonbb_M1252018 ttHToNonbb_M1252018 > output_ttHToNonbb_M1252018.out &
./Task.exe List_Preskim/Filelist_ttHTobb_M1252016APV.list ttHTobb_M1252016APV ttHTobb_M1252016APV > output_ttHTobb_M1252016APV.out &
./Task.exe List_Preskim/Filelist_ttHTobb_M1252016.list ttHTobb_M1252016 ttHTobb_M1252016 > output_ttHTobb_M1252016.out &
sleep 1m
./Task.exe List_Preskim/Filelist_ttHTobb_M1252017.list ttHTobb_M1252017 ttHTobb_M1252017 > output_ttHTobb_M1252017.out &
./Task.exe List_Preskim/Filelist_ttHTobb_M1252018.list ttHTobb_M1252018 ttHTobb_M1252018 > output_ttHTobb_M1252018.out &
