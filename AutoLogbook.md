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


## Example of modification in main.cpp file
```
cout << "\n\n ===> START My code TEST <===";

// Set the default values of the gate and amplitude of all the channels
DataRecipe_ptr->GetMainDetault()->minAmplitude = 0.; // set minimal amplitude no ampl selection)\n
DataRecipe_ptr->GetMainDetault()->minAmplGate = 100.; // set start time for the gate
DataRecipe_ptr->GetMainDetault()->maxAmplGate = 140.; // set start time for the gate

DataRecipe_ptr->Configure((indir+"DataConfig.txt").c_str()); //open configuration file, and configure data processing parameters\n


// Setting the custom values for individual channels
DataRecipe_ptr->GetMainParam(0)->minAmplitude = 0.;
DataRecipe_ptr->GetMainParam(0)->minAmplGate = 100.; // set start time for the gate
DataRecipe_ptr->GetMainParam(0)->maxAmplGate = 140.; // set start time for the gate

DataRecipe_ptr->GetMainParam(1)->minAmplitude = 0.;
DataRecipe_ptr->GetMainParam(0)->minAmplGate = 100.; // set start time for the gate
DataRecipe_ptr->GetMainParam(0)->maxAmplGate = 140.; // set start time for the gate

DataRecipe_ptr->GetMainParam(16)->minAmplitude = 5.;
DataRecipe_ptr->GetMainParam(0)->minAmplGate = 100.; // set start time for the gate
DataRecipe_ptr->GetMainParam(0)->maxAmplGate = 140.; // set start time for the gate

DataRecipe_ptr->PrintOut();

cout << " ===> END  My code TEST <===\n\n";
```
        
