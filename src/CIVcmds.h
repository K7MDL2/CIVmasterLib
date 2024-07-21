/* 
	CIVcmds.h - Library for communication via ICOM's CI-V bus
	Created by Wilfried Dilling, DK8RW, Mai 05, 2022
	Released into the public domain
	
	Definition of ICOM command set (only sub set as required!)
	To be included into CIV.cpp and all modules which may use one or more of these definitions
*/
#ifndef CIVcmds_h
#define CIVcmds_h


// command "body" of the CIV commands currently in use

constexpr uint8_t CIV_C_USB_D0_F2_SEND[] 			= {5,0x26,0x00,0x01,0x00,0x02};   // selected VFO; mod USB; Data OFF; RX_filter F2;
constexpr uint8_t CIV_C_USB_D1_F2_SEND[] 			= {5,0x26,0x00,0x01,0x01,0x02};   // selected VFO; mod USB; Data ON; RX_filter F2;
constexpr uint8_t CIV_C_LSB_D0_F2_SEND[] 			= {5,0x26,0x00,0x00,0x00,0x02};   // selected VFO; mod USB; Data OFF; RX_filter F2;
constexpr uint8_t CIV_C_LSB_D1_F2_SEND[] 			= {5,0x26,0x00,0x00,0x01,0x02};   // selected VFO; mod USB; Data ON; RX_filter F2;
constexpr uint8_t CIV_C_FM_D1_F1_SEND[] 			= {5,0x26,0x00,0x05,0x01,0x01};   // selected VFO; mod USB; Data ON; RX_filter F2;

constexpr uint8_t CIV_C_MOD_SET[] 			      = {5,0x26,0x00,0x01,0x00,0x01};   // cmd 26; selected VFO; mode, data on/off(0-1), filter (1-3);

constexpr uint8_t CIV_C_ATTN_OFF_READ[] 	= {2,0x11,0x00};                 // Atten OFF
constexpr uint8_t CIV_C_ATTN_ON_READ[] 		= {2,0x11,0x01};                 // Atten 10dB (144, 432, 1200 bands only)
constexpr uint8_t CIV_C_SPLIT_OFF_READ[] 	= {2,0x0F,0x00};                 // read Split OFF
constexpr uint8_t CIV_C_SPLIT_ON_READ[] 	= {2,0x0F,0x01};                 // read split ON
constexpr uint8_t CIV_C_SPLIT_OFF_SEND[] 	= {2,0x0F,0x01};                 // set split OFF
constexpr uint8_t CIV_C_SPLIT_ON_SEND[] 	= {2,0x0F,0x01};                 // Set split ON

constexpr uint8_t CIV_C_RFGAIN[] 	    = {2,0x14,0x02};                 // send/read RF Gain
constexpr uint8_t CIV_C_AFGAIN[] 	    = {2,0x14,0x01};                 // send/read AF Gain
constexpr uint8_t CIV_C_RFPOWER[]     = {2,0x14,0x0A};                 // send/read selected bands RF power
constexpr uint8_t CIV_C_S_MTR_LVL[]   = {2,0x15,0x02};                 // send/read S-meter level (00 00 to 02 55)  00 00 = S0, 01 20 = S9, 02 41 = S9+60dB

constexpr uint8_t CIV_C_PREAMP[] 	    = {2,0x16,0x02};                 // send/read preamp 00 = OFF, 01 = ON
constexpr uint8_t CIV_C_AGC[] 	      = {2,0x16,0x12};                 // send/read AGC  01 = FAST, 02 = MID, 03 = SLOW

constexpr uint8_t CIV_C_CW_MSGS[] 	  = {1,0x17};                 // Send CW messages see page 17 of prog manual for char table

constexpr uint8_t CIV_C_F_SEND[] 			= {1,0x00};                 // send operating frequency to all
constexpr uint8_t CIV_C_F1_SEND[] 		= {1,0x05};                 // send operating frequency to one
constexpr uint8_t CIV_C_F_READ[] 		  = {1,0x03};                 // read operating frequency

constexpr uint8_t CIV_C_F26_READ[] 		= {2,0x26,0x00};                 // read selected VFO m data, filt
constexpr uint8_t CIV_C_F26_SEND[] 		= {2,0x26,0x00};                 // send selected vfo mode, data, filter

constexpr uint8_t CIV_C_F25A_SEND[]   = {2,0x25,0x00};  // read VFO A selected vfo freq, mode, data, filter
constexpr uint8_t CIV_C_F25B_SEND[] 	= {2,0x25,0x01};  // read VFO B freq, mode, data, filter

constexpr uint8_t CIV_C_BSTACK[] 	    = {2,0x1A,0x01};            // send/read BandStack contents - see page 19 of prog manual.  
                                                                  // data byte 1 0xyy = Freq band code
                                                                  // dat abyte 2 0xzz = register code 01, 02 or 03
                                                                  // to read 432 band stack register 1 use 0x1A,0x01,0x02,0x01

constexpr uint8_t CIV_C_MOD_SEND[] 		= {1,0x01};                 // send Modulation Mode to all
constexpr uint8_t CIV_C_MOD1_SEND[] 	= {1,0x06};                 // send Modulation Mode to one
constexpr uint8_t CIV_C_MOD_USB_F1_SEND[] = {3,0x06,0x01,0x01};       // send USB Filter 1 
constexpr uint8_t CIV_C_MOD_USB__SEND[] 	= {2,0x06,0x01};       // send USB Filter 1 
constexpr uint8_t CIV_C_MOD_READ[] 	  = {1,0x04};               	// read Modulation Mode in use

constexpr uint8_t CIV_C_MY_POSIT_READ[] = {2,0x23,0x00};          // read MMy Position

constexpr uint8_t CIV_C_RF_POW[]      = {2,0x14,0x0A};            // send / read max RF power setting (0..255 == 0 .. 100%)

constexpr uint8_t CIV_C_TRX_ON_OFF[]  = {1,0x18};                 // switch radio ON/OFF

constexpr uint8_t CIV_C_TRX_ID[]      = {2,0x19,0x00};            // ID query

constexpr uint8_t CIV_C_TX[]    			= {2,0x1C,0x00};            // query of TX-State 00=OFF, 01=ON

// the following three commands don't fit for IC7100 !!!
constexpr uint8_t CIV_C_DATE[]        = {4,0x1A,0x05,0x00,0x94};  // + 0x20 0x20 0x04 0x27 for 27.4.2020
constexpr uint8_t CIV_C_TIME[]        = {4,0x1A,0x05,0x00,0x95};  // + 0x19 0x57 for 19:57
constexpr uint8_t CIV_C_UTC[]         = {4,0x1A,0x05,0x00,0x96};  // + 0x01,0x00,0x00 = +1h delta of UTC to MEZ
constexpr uint8_t CIV_C_UTC_READ[]    = {2,0x1A,0x05};  // + 0x01,0x00,0x00 = +1h delta of UTC to MEZ
constexpr uint8_t CIV_C_UTC_SEND[]    = {4,0x1A,0x05,0x00,0x96};  // + 0x01,0x00,0x00 = +1h delta of UTC to MEZ


// the following commands will be used by the client
constexpr uint8_t CIV_C_OK[]          = {1,0xFB};			// return OK  (no command/subcommand used in this case)
constexpr uint8_t CIV_C_NOK[]         = {1,0xFA};			// return NOK (no command/subcommand used in this case)

// definition of the fixed data section

constexpr uint8_t CIV_D_NIX[]         = {0,0x00};        // no data at all
constexpr uint8_t CIV_D_ON[]          = {1,0x01};        // ON
constexpr uint8_t CIV_D_OFF[]         = {1,0x00};        // OFF

/*
// ToDo:  Table of commands for message lookup
enum cmd_lookup {
    CIV_C_USB_D0_F2_SEND[] 			= {5,0x26,0x00,0x01,0x00,0x02};   // selected VFO; mod USB; Data OFF; RX_filter F2;
    CIV_C_USB_D1_F2_SEND[] 			= {5,0x26,0x00,0x01,0x01,0x02};   // selected VFO; mod USB; Data ON; RX_filter F2;
    CIV_C_LSB_D0_F2_SEND[] 			= {5,0x26,0x00,0x00,0x00,0x02};   // selected VFO; mod USB; Data OFF; RX_filter F2;
    CIV_C_LSB_D1_F2_SEND[] 			= {5,0x26,0x00,0x00,0x01,0x02};   // selected VFO; mod USB; Data ON; RX_filter F2;
    CIV_C_FM_D1_F1_SEND[] 			= {5,0x26,0x00,0x05,0x01,0x01};   // selected VFO; mod USB; Data ON; RX_filter F2;

};


constexpr uint8_t CIV_C_MOD_SET[] 			      = {5,0x26,0x00,0x01,0x00,0x01};   // cmd 26; selected VFO; mode, data on/off(0-1), filter (1-3);

constexpr uint8_t CIV_C_ATTN_OFF_READ[] 	= {2,0x11,0x00};                 // Atten OFF
constexpr uint8_t CIV_C_ATTN_ON_READ[] 		= {2,0x11,0x01};                 // Atten 10dB (144, 432, 1200 bands only)
constexpr uint8_t CIV_C_SPLIT_OFF_READ[] 	= {2,0x0F,0x00};                 // read Split OFF
constexpr uint8_t CIV_C_SPLIT_ON_READ[] 	= {2,0x0F,0x01};                 // read split ON
constexpr uint8_t CIV_C_SPLIT_OFF_SEND[] 	= {2,0x0F,0x01};                 // set split OFF
constexpr uint8_t CIV_C_SPLIT_ON_SEND[] 	= {2,0x0F,0x01};                 // Set split ON

constexpr uint8_t CIV_C_RFGAIN[] 	    = {2,0x14,0x02};                 // send/read RF Gain
constexpr uint8_t CIV_C_AFGAIN[] 	    = {2,0x14,0x01};                 // send/read AF Gain
constexpr uint8_t CIV_C_RFPOWER[]     = {2,0x14,0x0A};                 // send/read selected bands RF power
constexpr uint8_t CIV_C_S_MTR_LVL[]   = {2,0x15,0x02};                 // send/read S-meter level (00 00 to 02 55)  00 00 = S0, 01 20 = S9, 02 41 = S9+60dB

constexpr uint8_t CIV_C_PREAMP[] 	    = {2,0x16,0x02};                 // send/read preamp 00 = OFF, 01 = ON
constexpr uint8_t CIV_C_AGC[] 	      = {2,0x16,0x12};                 // send/read AGC  01 = FAST, 02 = MID, 03 = SLOW

constexpr uint8_t CIV_C_CW_MSGS[] 	  = {1,0x17};                 // Send CW messages see page 17 of prog manual for char table

constexpr uint8_t CIV_C_F_SEND[] 			= {1,0x00};                 // send operating frequency to all
constexpr uint8_t CIV_C_F1_SEND[] 		= {1,0x05};                 // send operating frequency to one
constexpr uint8_t CIV_C_F_READ[] 		  = {1,0x03};                 // read operating frequency

constexpr uint8_t CIV_C_F26_READ[] 		= {2,0x26,0x00};                 // read selected VFO m data, filt
constexpr uint8_t CIV_C_F26_SEND[] 		= {2,0x26,0x00};                 // send selected vfo mode, data, filter

constexpr uint8_t CIV_C_F25A_SEND[]   = {2,0x25,0x00};  // read VFO A selected vfo freq, mode, data, filter
constexpr uint8_t CIV_C_F25B_SEND[] 	= {2,0x25,0x01};  // read VFO B freq, mode, data, filter

constexpr uint8_t CIV_C_BSTACK[] 	    = {2,0x1A,0x01};            // send/read BandStack contents - see page 19 of prog manual.  
                                                                  // data byte 1 0xyy = Freq band code
                                                                  // dat abyte 2 0xzz = register code 01, 02 or 03
                                                                  // to read 432 band stack register 1 use 0x1A,0x01,0x02,0x01

constexpr uint8_t CIV_C_MOD_SEND[] 		= {1,0x01};                 // send Modulation Mode to all
constexpr uint8_t CIV_C_MOD1_SEND[] 	= {1,0x06};                 // send Modulation Mode to one
constexpr uint8_t CIV_C_MOD_USB_F1_SEND[] = {3,0x06,0x01,0x01};       // send USB Filter 1 
constexpr uint8_t CIV_C_MOD_USB__SEND[] 	= {2,0x06,0x01};       // send USB Filter 1 
constexpr uint8_t CIV_C_MOD_READ[] 	  = {1,0x04};               	// read Modulation Mode in use

constexpr uint8_t CIV_C_MY_POSIT_READ[] = {2,0x23,0x00};          // read MMy Position

constexpr uint8_t CIV_C_RF_POW[]      = {2,0x14,0x0A};            // send / read max RF power setting (0..255 == 0 .. 100%)

constexpr uint8_t CIV_C_TRX_ON_OFF[]  = {1,0x18};                 // switch radio ON/OFF

constexpr uint8_t CIV_C_TRX_ID[]      = {2,0x19,0x00};            // ID query

constexpr uint8_t CIV_C_TX[]    			= {2,0x1C,0x00};            // query of TX-State 00=OFF, 01=ON

// the following three commands don't fit for IC7100 !!!
constexpr uint8_t CIV_C_DATE[]        = {4,0x1A,0x05,0x00,0x94};  // + 0x20 0x20 0x04 0x27 for 27.4.2020
constexpr uint8_t CIV_C_TIME[]        = {4,0x1A,0x05,0x00,0x95};  // + 0x19 0x57 for 19:57
constexpr uint8_t CIV_C_UTC[]         = {4,0x1A,0x05,0x00,0x96};  // + 0x01,0x00,0x00 = +1h delta of UTC to MEZ
constexpr uint8_t CIV_C_UTC_READ[]    = {2,0x1A,0x05};  // + 0x01,0x00,0x00 = +1h delta of UTC to MEZ
constexpr uint8_t CIV_C_UTC_SEND[]    = {4,0x1A,0x05,0x00,0x96};  /

*/
// definition of command sequences to switch from "Data" mode (e.g.FT8) to "Voice" Mode (e.g. USB)

// ICOM has implemented such a mode switch in the meantime by a new SW version (IC705, IC7300, IC9700)
// therefore, this functionality will not be developed further in the future. But it remains in this SW
// due to backward compatibility reasons

// suitable for IC7100, IC705, IC7300; IC9700 unless otherwise noted

// known incompatibilies:

// sending this command to IC7300/IC9700 switches off the opening message
// 0x1A,0x05,0x00,0x90,0x00   Mod source in Data Off Mode -> MIC;             !!! IC7100 only !!!
// 0x1A,0x05,0x00,0x90        opening message on/off                          !!! IC7300, IC9700 !!!

// sending this command to IC7300 / IC9700 ruins the opening message
// 0x1A,0x05,0x00,0x91,0x03   Mod source in Data Mode - USB;                  !!! IC7100 only !!!
// 0x1A,0x05,0x00,0x91        defining the content of the opening message     !!! IC7300, IC9700 !!!

// 0x1A,0x05,0x00,0x94        set date                                        !!! not for IC7100 !!!
// 0x1A,0x05,0x00,0x95        set time                                        !!! not for IC7100 !!!
// 0x1A,0x05,0x00,0x96        set UTC offset                                  !!! not for IC7100 !!!



#define SEQU_MAX_CMD_LENGTH		6

// IC7100:

constexpr uint8_t DATA_MODE_7100[][SEQU_MAX_CMD_LENGTH] = { // Switch to Data Mode:    30bytes

    { 3,0x06,0x01,0x01},             // mod USB; RX_filter F1;  
    { 3,0x16,0x56,0x00},             // RX_filter SHARP;
    { 3,0x16,0x58,0x00},             // TX_filter WIDE;
    { 3,0x16,0x44,0x00},             // Comp OFF;
    { 3,0x16,0x40,0x00},             // Noise_Red OFF;
    { 3,0x16,0x22,0x00},             // Noise_Bl OFF;
    { 3,0x16,0x41,0x00},             // Auto Notch OFF;
    { 5,0x1A,0x05,0x00,0x90,0x03},   // Mod source in Data OFF Mode - USB;
    { 4,0x14,0x0A,0x00, 0x77}        // Power 30%;
};

constexpr uint8_t VOICE_MODE_7100[][SEQU_MAX_CMD_LENGTH] = { //Switch to Voice Mode:  24bytes

 { 3,0x06,0x01,0x02},             // mod USB; RX_filter F2;
 { 3,0x16,0x56,0x01},             // RX_filter SOFT;
 { 3,0x16,0x58,0x01},             // TX_filter MID;
 { 3,0x16,0x44,0x01},             // Comp ON;
 { 3,0x16,0x40,0x01},             // Noise_Red ON;
 { 5,0x1A,0x05,0x00,0x90,0x02},   // Mod source in Data Off Mode - MIC,ACC;
 { 4,0x14,0x0A,0x02,0x55}         // Power 100%;

};

// IC705 and IC7300:

constexpr uint8_t DATA_MODE_7300[][SEQU_MAX_CMD_LENGTH] = { // Switch to Data Mode:        27bytes
  { 5,0x26,0x00,0x01,0x01,0x01},   // selected VFO; mod USB; Data ON; RX_filter F1;
  { 3,0x16,0x56,0x00},             // RX_filter SHARP;
  { 3,0x16,0x58,0x00},             // TX_filter WIDE;
  { 3,0x16,0x44,0x00},             // Comp OFF;
  { 3,0x16,0x40,0x00},             // Noise_Red OFF;
  { 3,0x16,0x22,0x00},             // Noise_Bl OFF;
  { 3,0x16,0x41,0x00},             // Auto Notch OFF;
  { 4,0x14,0x0A,0x00, 0x77}        // Power 30%;
};


constexpr uint8_t VOICE_MODE_7300[][SEQU_MAX_CMD_LENGTH] = { //Switch to Voice Mode:       21bytes
 { 5,0x26,0x00,0x01,0x00,0x02},   // selected VFO; mod USB; Data OFF; RX_filter F2;
 { 3,0x16,0x56,0x01},             // RX_filter SOFT;
 { 3,0x16,0x58,0x01},             // TX_filter MID;
 { 3,0x16,0x44,0x01},             // Comp ON;
 { 3,0x16,0x40,0x01},             // Noise_Red ON;
 { 5,0x1A,0x05,0x00,0x66,0x00},   // Mod source in Data Off Mode - MIC
 { 4,0x14,0x0A,0x02,0x55}         // Power 100%;
};

// IC9700:

constexpr uint8_t DATA_MODE_9700[][SEQU_MAX_CMD_LENGTH] = { // Switch to Data Mode:
//  { 1,0x07},                       // select VFO mode
  { 2,0x07,0x00},                  // select VFO A
  { 5,0x26,0x00,0x01,0x01,0x01},   // selected VFO; mod USB; Data ON; RX_filter F1;
  { 3,0x16,0x56,0x00},             // RX_filter SHARP;
  { 3,0x16,0x58,0x00},             // TX_filter WIDE;
  { 3,0x16,0x44,0x00},             // Comp OFF;
  { 3,0x16,0x40,0x00},             // Noise_Red OFF;
  { 3,0x16,0x22,0x00},             // Noise_Bl OFF;
  { 3,0x16,0x41,0x00}              // Auto Notch OFF;
//  { 4,0x14,0x0A,0x00, 0x77}        // Power 30%; that's normal, so doesn't need to be changed
};

constexpr uint8_t VOICE_MODE_9700[][SEQU_MAX_CMD_LENGTH] = { //Switch to Voice Mode:
// { 1,0x07},                       // select VFO mode (sicherheitshalber)
 { 2,0x07,0x00},                  // select VFO A (sicherheitshalber)
 { 5,0x26,0x00,0x01,0x00,0x02},   // selected VFO; mod USB; Data OFF; RX_filter F2;
 { 3,0x16,0x56,0x01},             // RX_filter SOFT;
 { 3,0x16,0x58,0x01},             // TX_filter MID;
// { 3,0x16,0x44,0x01},             // Comp ON;
// { 3,0x16,0x40,0x01},             // Noise_Red ON;
 { 1,0x08},                       // Sel Memory mode
 { 3,0x08,0x01,0x06}              // Sel Call Ch C1;
};


#endif
