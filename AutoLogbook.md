# Test of automatic analysis

## From Dima F. Email:
> With command line you can configure all parameters, but you need to do it the code of main.cpp file.
>Line 174 `DataRecipe_ptr->GetMainDetault()->minAmplitude = 0.; // set minimal amplitude no ampl selection)\n` 
>Parameters list you can find in files DigDataRecipe and DigVariables.

- The gate for this integration is the same that I am writing in the program?
> Take in account, that gate is individually for each channel, you can check it by draw parameters button (gate will be indicated by red asterisk in waveform), or in terminal by printing parameters.

- and the charge is negative. This is okay?
> To simulate analog integrator, no base line subtracted for charge_gate. For correct measurements, You need to set gate out of signal and measure pedestal. If pedestal is negative too, it is OK, because Result charge-pedestal should be positive.

- How these parameters can be configured from the console? Is it is possible to assign different gate time to each channel with this?
> Default parameters are applied to all channels.
>To configure individually channel call `GetMainParam(int Ch)` 
>After configuration `DataRecipe_ptr->Configure((indir+"DataConfig.txt").c_str());`
>Use `DigDataRecipe::PrintOut` To check parameters
