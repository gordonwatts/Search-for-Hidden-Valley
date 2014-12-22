void runChainPlot()
{
  // compile the darn thing.
  gSystem->CompileMacro("ChainPlot.C");
  ChainPlot *cp = new ChainPlot();

  // Open the file.
  TFile *f = TFile::Open("ntup_aod_03_3701_3750.root", "READ");
  TTree *t = (TTree*)f->Get("physics");
  if (t == 0) {
    cout << "Could not find the tree";
    return;
  }

  // Run the guy.
  t->Process(cp);
}