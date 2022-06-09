rm -rf hadddir
rm -rf Had_*.root
mkdir hadddir
cp WJetsToLNu_*results.root hadddir
hadd Had_WJetsToLNu.root hadddir/*.root > haddbackup.txt

rm hadddir/*
cp TTTo*results.root hadddir
hadd Had_TTbar.root hadddir/*.root >>haddbackup.txt

rm hadddir/*
cp TT*results.root hadddir
rm hadddir/TTTo*results.root
hadd Had_TTX.root hadddir/*.root >> haddbackup.txt

rm hadddir/*
cp *results.root hadddir
rm hadddir/TT*.root hadddir/WJetsToLNu*.root hadddir/*Single*.root hadddir/*VBSW*H*.root
hadd Had_Other.root hadddir/*.root >> haddbackup.txt

hadd Had_allbkg.root Had_*.root

hadd Had_data.root *Single*results.root


:<<!
rm SingleElectron2016.root 
rm SingleElectron2017.root 
rm SingleElectron2018.root 
rm SingleElectron.root 
rm SingleMuon2016.root 
rm SingleMuon2017.root 
rm SingleMuon2018.root 
rm SingleMuon.root 

mkdir hadddir
cp SingleElectron2016* hadddir
hadd SingleElectron2016.root hadddir/*.root

rm hadddir/*
cp SingleElectron2017* hadddir
hadd SingleElectron2017.root hadddir/*.root

rm hadddir/*
cp SingleElectron2018* hadddir
hadd SingleElectron2018.root hadddir/*.root

rm hadddir/*
cp SingleMuon2016* hadddir
hadd SingleMuon2016.root hadddir/*.root

rm hadddir/*
cp SingleMuon2017* hadddir
hadd SingleMuon2017.root hadddir/*.root

rm hadddir/*
cp SingleMuon2018* hadddir
hadd SingleMuon2018.root hadddir/*.root

hadd SingleElectron.root SingleElectron2016.root SingleElectron2017.root SingleElectron2018.root
hadd SingleMuon.root SingleMuon2016.root SingleMuon2017.root SingleMuon2018.root

rm -r hadddir

rm VBSWZH.root VBSWWH.root sig.root ttbb.root tt1l.root tt2l.root ttX.root WJets.root bkg.root

mkdir hadddir
cp *SVBSWWH201*_results.root hadddir
hadd VBSWWH.root hadddir/*.root

rm hadddir/*
cp *VBSWZH201*_results.root hadddir
hadd VBSWZH.root hadddir/*.root

hadd sig.root VBSWWH.root VBSWZH.root

rm hadddir/*
cp TTbb*_results.root hadddir
hadd ttbb.root hadddir/*.root

rm hadddir/*
cp TTToSemi*_results.root hadddir
hadd tt1l.root hadddir/*.root

rm hadddir/*
cp TTTo2L2Nu*_results.root hadddir
hadd tt2l.root hadddir/*.root

rm hadddir/*
cp ttHJetTo*_results.root hadddir
cp TTW*_results.root hadddir
cp TTZ*_results.root hadddir
hadd ttX.root hadddir/*.root

rm hadddir/*
cp WJetsToLNu*_results.root hadddir
rm hadddir/WJetsToLNu201*HT0To70*_results.root
hadd WJets.root hadddir/*.root

hadd bkg.root ttbb.root tt1l.root tt2l.root ttX.root WJets.root





rm -r hadddir
!
