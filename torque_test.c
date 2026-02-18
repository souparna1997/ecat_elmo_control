//This is a code to run a BLDC motor (Maxon EC 45 411812) in profiled torque mode using the Elmo Golo Solo Twitter driver and SOEM as the communication platform
//Author: Souparna Gangopadhyay
//Date: 02/06/2026
//Email: souparna@stanford.edu

// steam@nuc:~/Projects/SOEM/build/samples/slaveinfo$ sudo ./slaveinfo enp86s0 -sdo
// [sudo] password for steam: 
// SOEM (Simple Open EtherCAT Master)
// Slaveinfo
// Starting slaveinfo
// ecx_init on enp86s0 succeeded.
// 1 slaves found and configured.
// Calculated workcounter 3

// Slave:1
//  Name:? M:0000009a I:00030924
//  Output size: 128bits
//  Input size: 112bits
//  State: 4
//  Delay: 0[ns]
//  Has DC: 1
//  DCParentport:0
//  Activeports:1.0.0.0
//  Configured address: 1001
//  Man: 0000009a ID: 00030924 Rev: 00010420
//  SM0 A:1800 L: 140 F:00010026 Type:1
//  SM1 A:1900 L: 140 F:00010022 Type:2
//  SM2 A:1100 L:  16 F:00010064 Type:3
//  SM3 A:1180 L:  14 F:00010020 Type:4
//  FMMU0 Ls:00000000 Ll:  16 Lsb:0 Leb:7 Ps:1100 Psb:0 Ty:02 Act:01
//  FMMU1 Ls:00000010 Ll:  14 Lsb:0 Leb:7 Ps:1180 Psb:0 Ty:01 Act:01
//  FMMU2 Ls:0000001e Ll:   1 Lsb:0 Leb:7 Ps:080d Psb:0 Ty:01 Act:01
//  FMMUfunc 0:1 1:2 2:0 3:0
//  MBX length wr: 140 rd: 140 MBX protocols : 0e
//  CoE details: 3f FoE details: 01 EoE details: 01 SoE details: 00
//  Ebus current: 0[mA]
//  only LRD/LWR:0
//  CoE Object Description found, 218 entries.
// 0x1000      "Device Type"                                 [VAR]
//     0x00      "Device Type"                                 [UNSIGNED32       R_R_R_]      0x00020192 / 131474
// 0x1001      "Error Register"                              [VAR]
//     0x00      "Error Register"                              [UNSIGNED8        R_R_R_]      0x00 / 0
// 0x1002      "Manufacturer Status Register"                [VAR]
//     0x00      "Manufacturer Status Register"                [UNSIGNED32       R_R_R_]      0x0600c400 / 100713472
// 0x1003      "Predefined error field"                      [ARRAY  maxsub(0x10 / 16)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        RWRWRW]      0x07 / 7
//     0x01      "standard error field 1"                      [UNSIGNED32       R_R_R_]      0x00008130 / 33072
//     0x02      "standard error field 2"                      [UNSIGNED32       R_R_R_]      0x00008130 / 33072
//     0x03      "standard error field 3"                      [UNSIGNED32       R_R_R_]      0x00008130 / 33072
//     0x04      "standard error field 4"                      [UNSIGNED32       R_R_R_]      0x00008130 / 33072
//     0x05      "standard error field 5"                      [UNSIGNED32       R_R_R_]      0x00008130 / 33072
//     0x06      "standard error field 6"                      [UNSIGNED32       R_R_R_]      0x00008130 / 33072
//     0x07      "standard error field 7"                      [UNSIGNED32       R_R_R_]      0x00008130 / 33072
// 0x1008      "Manufacture Device Name"                     [VAR]
//     0x00      "Manufacture Device Name"                     [VISIBLE_STR(512) R_R_R_]      "Twitter""
// 0x1009      "Manufacture Hardware Version"                [VAR]
//     0x00      "Manufacture Hardware Version"                [VISIBLE_STR(512) R_R_R_]      "1.1.3.0""
// 0x100a      "Manufacture Software Version"                [VAR]
//     0x00      "Manufacture Software Version"                [VISIBLE_STR(264) R_R_R_]      "Twitter 01.01.16.00 08Mar2020B01G""
// 0x100b      "Bootloader Version"                          [VAR]
//     0x00      "Bootloader Version"                          [VISIBLE_STR(64)  R_R_R_]      "1.1.3.35""
// 0x1010      "Store Parameters"                            [ARRAY  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Store All Parameters"                        [UNSIGNED32       RWRWRW]      0x00000001 / 1
// 0x1011      "Restore Parameters"                          [ARRAY  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Restore All Parameters"                      [UNSIGNED32       RWRWRW]      0x00000001 / 1
// 0x1018      "Identity Object"                             [RECORD  maxsub(0x04 / 4)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x04 / 4
//     0x01      "Vendor ID"                                   [UNSIGNED32       R_R_R_]      0x0000009a / 154
//     0x02      "Product Code"                                [UNSIGNED32       R_R_R_]      0x00030924 / 198948
//     0x03      "Revision Number"                             [UNSIGNED32       R_R_R_]      0x00010420 / 66592
//     0x04      "Serial Number"                               [UNSIGNED32       R_R_R_]      0x01379e89 / 20422281
// 0x10e0      "Device ID Reload"                            [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Configured Alias Reg"                        [INTEGER16        RWRWRW]      0x0000 / 0
//     0x02      "Write Configured Alias Persistent"           [INTEGER16        RWRWRW]      0x0000 / 0
// 0x10f1      "Sync Monitor Setting"                        [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Local Error Reaction"                        [UNSIGNED32       R_R_R_]      0x00000002 / 2
//     0x02      "Sync Error Counter Limit"                    [UNSIGNED32       RWRWR_]      0x00000000 / 0
// 0x1600      "RPDO1 Mapping"                               [RECORD  maxsub(0x03 / 3)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x03 / 3
//     0x01      "Target Position"                             [UNSIGNED32       R_R_R_]      0x607a0020 / 1618608160
//     0x02      "Digital Outputs"                             [UNSIGNED32       R_R_R_]      0x60fe0120 / 1627259168
//     0x03      "Control word"                                [UNSIGNED32       R_R_R_]      0x60400010 / 1614807056
// 0x1601      "RPDO2 Mapping"                               [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Target Velocity"                             [UNSIGNED32       R_R_R_]      0x60ff0020 / 1627324448
//     0x02      "Control word"                                [UNSIGNED32       R_R_R_]      0x60400010 / 1614807056
// 0x1602      "RPDO3 Mapping"                               [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Target Torque"                               [UNSIGNED32       R_R_R_]      0x60710010 / 1618018320
//     0x02      "Control word"                                [UNSIGNED32       R_R_R_]      0x60400010 / 1614807056
// 0x1603      "RPDO4 Mapping"                               [RECORD  maxsub(0x04 / 4)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x04 / 4
//     0x01      "Target Position"                             [UNSIGNED32       R_R_R_]      0x607a0020 / 1618608160
//     0x02      "Digital Outputs"                             [UNSIGNED32       R_R_R_]      0x60fe0120 / 1627259168
//     0x03      "Velocity Offset"                             [UNSIGNED32       R_R_R_]      0x60b10020 / 1622212640
//     0x04      "Control word"                                [UNSIGNED32       R_R_R_]      0x60400010 / 1614807056
// 0x1604      "RPDO5 Mapping"                               [RECORD  maxsub(0x04 / 4)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x04 / 4
//     0x01      "Target Position"                             [UNSIGNED32       R_R_R_]      0x607a0020 / 1618608160
//     0x02      "Target Velocity"                             [UNSIGNED32       R_R_R_]      0x60ff0020 / 1627324448
//     0x03      "Max. Torque"                                 [UNSIGNED32       R_R_R_]      0x60720010 / 1618083856
//     0x04      "Control word"                                [UNSIGNED32       R_R_R_]      0x60400010 / 1614807056
// 0x1605      "RPDO6 Mapping"                               [RECORD  maxsub(0x07 / 7)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x07 / 7
//     0x01      "Target Position"                             [UNSIGNED32       R_R_R_]      0x607a0020 / 1618608160
//     0x02      "Target Velocity"                             [UNSIGNED32       R_R_R_]      0x60ff0020 / 1627324448
//     0x03      "Target Torque"                               [UNSIGNED32       R_R_R_]      0x60710010 / 1618018320
//     0x04      "Max. Torque"                                 [UNSIGNED32       R_R_R_]      0x60720010 / 1618083856
//     0x05      "Control word"                                [UNSIGNED32       R_R_R_]      0x60400010 / 1614807056
//     0x06      "Modes Of Operation"                          [UNSIGNED32       R_R_R_]      0x60600008 / 1616904200
//     0x07      "Padding"                                     [UNSIGNED32       R_R_R_]      0x00000008 / 8
// 0x1606      "RPDO7 Mapping"                               [RECORD  maxsub(0x06 / 6)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x06 / 6
//     0x01      "Target Position"                             [UNSIGNED32       R_R_R_]      0x607a0020 / 1618608160
//     0x02      "Digital Outputs"                             [UNSIGNED32       R_R_R_]      0x60fe0120 / 1627259168
//     0x03      "Target Velocity"                             [UNSIGNED32       R_R_R_]      0x60ff0020 / 1627324448
//     0x04      "Velocity Offset"                             [UNSIGNED32       R_R_R_]      0x60b10020 / 1622212640
//     0x05      "Torque Offset"                               [UNSIGNED32       R_R_R_]      0x60b20010 / 1622278160
//     0x06      "Control word"                                [UNSIGNED32       R_R_R_]      0x60400010 / 1614807056
// 0x1607      "RPDO8 Mapping"                               [RECORD  maxsub(0x08 / 8)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        RWR_R_]      0x00 / 0
// 0x1608      "RPDO9 Mapping"                               [RECORD  maxsub(0x08 / 8)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        RWR_R_]      0x00 / 0
// 0x160a      "RPDO_160A Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Control word"                                [UNSIGNED32       R_R_R_]      0x60400010 / 1614807056
// 0x160b      "RPDO_160B Mapping"                           [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Modes Of Operation"                          [UNSIGNED32       R_R_R_]      0x60600008 / 1616904200
//     0x02      "Padding"                                     [UNSIGNED32       R_R_R_]      0x00000008 / 8
// 0x160c      "RPDO_160C Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Target Torque"                               [UNSIGNED32       R_R_R_]      0x60710010 / 1618018320
// 0x160d      "RPDO_160D Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Max. Torque"                                 [UNSIGNED32       R_R_R_]      0x60720010 / 1618083856
// 0x160e      "RPDO_160E Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Max. Current"                                [UNSIGNED32       R_R_R_]      0x60730010 / 1618149392
// 0x160f      "RPDO_160F Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Target Position"                             [UNSIGNED32       R_R_R_]      0x607a0020 / 1618608160
// 0x1611      "RPDO_1611 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Profile Velocity"                            [UNSIGNED32       R_R_R_]      0x60810020 / 1619066912
// 0x1612      "RPDO_1612 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "End Velocity"                                [UNSIGNED32       R_R_R_]      0x60820020 / 1619132448
// 0x1613      "RPDO_1613 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Profile Acceleration"                        [UNSIGNED32       R_R_R_]      0x60830020 / 1619197984
// 0x1614      "RPDO_1614 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Profile Deceleration"                        [UNSIGNED32       R_R_R_]      0x60840020 / 1619263520
// 0x1615      "RPDO_1615 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Torque Slope"                                [UNSIGNED32       R_R_R_]      0x60870020 / 1619460128
// 0x1616      "RPDO_1616 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Position Offset"                             [UNSIGNED32       R_R_R_]      0x60b00020 / 1622147104
// 0x1617      "RPDO_1617 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Velocity Offset"                             [UNSIGNED32       R_R_R_]      0x60b10020 / 1622212640
// 0x1618      "RPDO_1618 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Torque Offset"                               [UNSIGNED32       R_R_R_]      0x60b20010 / 1622278160
// 0x1619      "RPDO_1619 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Touch Probe Function"                        [UNSIGNED32       R_R_R_]      0x60b80010 / 1622671376
// 0x161a      "RPDO_161A Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Gain scheduling manual index"                [UNSIGNED32       R_R_R_]      0x2e000010 / 771751952
// 0x161c      "RPDO_161C Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Target Velocity"                             [UNSIGNED32       R_R_R_]      0x60ff0020 / 1627324448
// 0x161d      "RPDO_161D Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Digital Outputs"                             [UNSIGNED32       R_R_R_]      0x60fe0120 / 1627259168
// 0x161e      "RPDO_161E Mapping"                           [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Polarity"                                    [UNSIGNED32       R_R_R_]      0x607e0008 / 1618870280
//     0x02      "Padding"                                     [UNSIGNED32       R_R_R_]      0x00000008 / 8
// 0x161f      "RPDO_161F Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Quick stop deceleration"                     [UNSIGNED32       R_R_R_]      0x60850020 / 1619329056
// 0x1620      "RPDO_1620 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Extended Outputs"                            [UNSIGNED32       R_R_R_]      0x22a10120 / 580976928
// 0x1621      "RPDO_1621 Mapping"                           [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Fast Reference"                              [UNSIGNED32       R_R_R_]      0x20050020 / 537198624
// 0x1a00      "TPDO1 Mapping"                               [RECORD  maxsub(0x03 / 3)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x03 / 3
//     0x01      "Actual Position"                             [UNSIGNED32       R_R_R_]      0x60640020 / 1617166368
//     0x02      "Digital Inputs"                              [UNSIGNED32       R_R_R_]      0x60fd0020 / 1627193376
//     0x03      "Statusword"                                  [UNSIGNED32       R_R_R_]      0x60410010 / 1614872592
// 0x1a01      "TPDO2 Mapping"                               [RECORD  maxsub(0x04 / 4)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x04 / 4
//     0x01      "Actual Position"                             [UNSIGNED32       R_R_R_]      0x60640020 / 1617166368
//     0x02      "Velocity Demand"                             [UNSIGNED32       R_R_R_]      0x606b0020 / 1617625120
//     0x03      "Torque Demand"                               [UNSIGNED32       R_R_R_]      0x60740010 / 1618214928
//     0x04      "Statusword"                                  [UNSIGNED32       R_R_R_]      0x60410010 / 1614872592
// 0x1a02      "TPDO3 Mapping"                               [RECORD  maxsub(0x05 / 5)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x05 / 5
//     0x01      "Actual Position"                             [UNSIGNED32       R_R_R_]      0x60640020 / 1617166368
//     0x02      "Actual Torque"                               [UNSIGNED32       R_R_R_]      0x60770010 / 1618411536
//     0x03      "Statusword"                                  [UNSIGNED32       R_R_R_]      0x60410010 / 1614872592
//     0x04      "Mode of operation display"                   [UNSIGNED32       R_R_R_]      0x60610008 / 1616969736
//     0x05      "Padding"                                     [UNSIGNED32       R_R_R_]      0x00000008 / 8
// 0x1a03      "TPDO4 Mapping"                               [RECORD  maxsub(0x04 / 4)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x04 / 4
//     0x01      "Actual Position"                             [UNSIGNED32       R_R_R_]      0x60640020 / 1617166368
//     0x02      "Digital Inputs"                              [UNSIGNED32       R_R_R_]      0x60fd0020 / 1627193376
//     0x03      "Actual Velocity"                             [UNSIGNED32       R_R_R_]      0x606c0020 / 1617690656
//     0x04      "Statusword"                                  [UNSIGNED32       R_R_R_]      0x60410010 / 1614872592
// 0x1a04      "TPDO5 Mapping"                               [RECORD  maxsub(0x06 / 6)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x06 / 6
//     0x01      "Actual Position"                             [UNSIGNED32       R_R_R_]      0x60640020 / 1617166368
//     0x02      "Position Following Error"                    [UNSIGNED32       R_R_R_]      0x60f40020 / 1626603552
//     0x03      "Actual Torque"                               [UNSIGNED32       R_R_R_]      0x60770010 / 1618411536
//     0x04      "Statusword"                                  [UNSIGNED32       R_R_R_]      0x60410010 / 1614872592
//     0x05      "Mode of operation display"                   [UNSIGNED32       R_R_R_]      0x60610008 / 1616969736
//     0x06      "Padding"                                     [UNSIGNED32       R_R_R_]      0x00000008 / 8
// 0x1a07      "TPDO8 Mapping"                               [RECORD  maxsub(0x08 / 8)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        RWR_R_]      0x00 / 0
// 0x1a08      "TPDO9 Mapping"                               [RECORD  maxsub(0x08 / 8)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        RWR_R_]      0x00 / 0
// 0x1a0a      "TPD0A Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Statusword"                                  [UNSIGNED32       R_R_R_]      0x60410010 / 1614872592
// 0x1a0b      "TPD0B Mapping"                               [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Mode of operation display"                   [UNSIGNED32       R_R_R_]      0x60610008 / 1616969736
//     0x02      "Padding"                                     [UNSIGNED32       R_R_R_]      0x00000008 / 8
// 0x1a0c      "TPD0C Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Position Demand [UU]"                        [UNSIGNED32       R_R_R_]      0x60620020 / 1617035296
// 0x1a0d      "TPD0D Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Actual position [counts]"                    [INTEGER32        R_R_R_]      0x60630020 / 1617100832
// 0x1a0e      "TPD0E Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Position actual value"                       [UNSIGNED32       R_R_R_]      0x60640020 / 1617166368
// 0x1a0f      "TPD0F Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Velocity sensor actual value [cnt/sec]"      [UNSIGNED32       R_R_R_]      0x60690020 / 1617494048
// 0x1a10      "TPD10 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Velocity Demmand [cnt/sec]"                  [UNSIGNED32       R_R_R_]      0x606b0020 / 1617625120
// 0x1a11      "TPD11 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Velocity Actual Value"                       [UNSIGNED32       R_R_R_]      0x606c0020 / 1617690656
// 0x1a12      "TPD12 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Torque demand value"                         [UNSIGNED32       R_R_R_]      0x60740010 / 1618214928
// 0x1a13      "TPD13 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Torque Actual value"                         [UNSIGNED32       R_R_R_]      0x60770010 / 1618411536
// 0x1a14      "TPD14 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Touch Probe status"                          [UNSIGNED32       R_R_R_]      0x60b90010 / 1622736912
// 0x1a15      "TPD15 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Touch Probe Position1 Positive"              [UNSIGNED32       R_R_R_]      0x60ba0020 / 1622802464
// 0x1a16      "TPD16 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Touch Probe Position1 Negative"              [UNSIGNED32       R_R_R_]      0x60bb0020 / 1622868000
// 0x1a17      "TPD17 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Touch Probe Position2 Positive"              [UNSIGNED32       R_R_R_]      0x60bc0020 / 1622933536
// 0x1a18      "TPD18 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "DC link circuit voltage"                     [UNSIGNED32       R_R_R_]      0x60790020 / 1618542624
// 0x1a19      "TPD19 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Position Following errror actual value"      [UNSIGNED32       R_R_R_]      0x60f40020 / 1626603552
// 0x1a1a      "TPD1A Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Control Effort [cnt/sec]"                    [UNSIGNED32       R_R_R_]      0x60fa0020 / 1626996768
// 0x1a1b      "TPD1B Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Position Demand Value [cnt]"                 [UNSIGNED32       R_R_R_]      0x60fc0020 / 1627127840
// 0x1a1c      "TPD1C Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Digital Inputs"                              [UNSIGNED32       R_R_R_]      0x60fd0020 / 1627193376
// 0x1a1d      "TPD1D Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Analog Input 1"                              [UNSIGNED32       R_R_R_]      0x22050110 / 570753296
// 0x1a1e      "TPD1E Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Auxiliary position actual value"             [UNSIGNED32       R_R_R_]      0x20a00020 / 547356704
// 0x1a1f      "TPD1F Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Current actual value"                        [UNSIGNED32       R_R_R_]      0x60780010 / 1618477072
// 0x1a20      "TPD20 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Touch Probe Position2 Negative"              [UNSIGNED32       R_R_R_]      0x60bd0020 / 1622999072
// 0x1a21      "TPD21 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Extra Status Reg"                            [UNSIGNED32       R_R_R_]      0x20850010 / 545587216
// 0x1a22      "TPD22 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Elmo Status Reg"                             [UNSIGNED32       R_R_R_]      0x10020020 / 268566560
// 0x1a23      "TPD23 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Extended Inputs"                             [UNSIGNED32       R_R_R_]      0x22020120 / 570556704
// 0x1a24      "TPD24 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "App Object"                                  [UNSIGNED32       R_R_R_]      0x22030020 / 570621984
// 0x1a26      "TPD26 Mapping"                               [RECORD  maxsub(0x01 / 1)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x01      "Error Code"                                  [UNSIGNED32       R_R_R_]      0x603f0010 / 1614741520
// 0x1c00      "SM Communication Type"                       [ARRAY  maxsub(0x04 / 4)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x04 / 4
//     0x01      "MailboxOut"                                  [UNSIGNED8        R_R_R_]      0x01 / 1
//     0x02      "MailboxIn"                                   [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x03      "Outputs"                                     [UNSIGNED8        R_R_R_]      0x03 / 3
//     0x04      "Inputs"                                      [UNSIGNED8        R_R_R_]      0x04 / 4
// 0x1c10      "SM0 PDO Assignment"                          [VAR]
//     0x00      "SM0 PDO Assignment"                          [UNSIGNED16       RWR_R_]      0x0000 / 0
// 0x1c11      "SM1 PDO Assignment"                          [VAR]
//     0x00      "SM1 PDO Assignment"                          [UNSIGNED16       RWR_R_]      0x0000 / 0
// 0x1c12      "SM2(Outputs) PDO Assignment"                 [ARRAY  maxsub(0x1e / 30)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        RWR_R_]      0x01 / 1
//     0x01      "SubIndex 001"                                [UNSIGNED16       RWRWRW]      0x1605 / 5637
// 0x1c13      "SM3(Inputs) PDO Assignment"                  [ARRAY  maxsub(0x23 / 35)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        RWR_R_]      0x01 / 1
//     0x01      "SubIndex 001"                                [UNSIGNED16       RWRWRW]      0x1a04 / 6660
// 0x1c32      "SM Outputs Parameters"                       [RECORD  maxsub(0x20 / 32)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x20 / 32
//     0x01      "Sync Mode"                                   [UNSIGNED16       RWRWRW]      0x0002 / 2
//     0x02      "cycle Time"                                  [UNSIGNED32       R_R_R_]      0x00000000 / 0
//     0x03      "Shift Time"                                  [UNSIGNED32       R_R_R_]      0x00000000 / 0
//     0x04      "Sync Mode Support"                           [UNSIGNED16       R_R_R_]      0xc005 / 49157
//     0x05      "Min. Cycle Time"                             [UNSIGNED32       R_R_R_]      0x0003d090 / 250000
//     0x06      "Calc And Copy Time"                          [UNSIGNED32       R_R_R_]      0x00000000 / 0
//     0x07      "SubIndex 007"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x08      "Command"                                     [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x09      "Delay Time"                                  [UNSIGNED32       R_R_R_]      0x00000000 / 0
//     0x0a      "SubIndex 00A"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x0b      "SM Event Missed Counter"                     [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x0c      "Cycle Exceeded Counter"                      [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x0d      "Shift Too Short Counter"                     [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x0e      "SubIndex 00E"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x0f      "SubIndex 00F"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x10      "SubIndex 010"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x11      "SubIndex 011"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x12      "SubIndex 012"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x13      "SubIndex 013"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x14      "SubIndex 014"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x15      "SubIndex 015"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x16      "SubIndex 016"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x17      "SubIndex 017"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x18      "SubIndex 018"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x19      "SubIndex 019"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x1a      "SubIndex 01A"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x1b      "SubIndex 01B"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x1c      "SubIndex 01C"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x1d      "SubIndex 01D"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x1e      "SubIndex 01E"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x1f      "SubIndex 01F"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x20      "Sync Error"                                  [UNSIGNED16       R_R_R_]      0x0000 / 0
// 0x1c33      "SM Inputs Parameters"                        [RECORD  maxsub(0x20 / 32)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x20 / 32
//     0x01      "Sync Mode"                                   [UNSIGNED16       RWRWRW]      0x0002 / 2
//     0x02      "Cycle Time"                                  [UNSIGNED32       R_R_R_]      0x00000000 / 0
//     0x03      "Shift Time"                                  [UNSIGNED32       R_R_R_]      0x00000000 / 0
//     0x04      "Sync Mode Support"                           [UNSIGNED16       R_R_R_]      0xc005 / 49157
//     0x05      "Min. Cycle Time"                             [UNSIGNED32       R_R_R_]      0x0003d090 / 250000
//     0x06      "Calc And Copy Time"                          [UNSIGNED32       R_R_R_]      0x00000000 / 0
//     0x07      "SubIndex 007"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x08      "Command"                                     [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x09      "Delay Time"                                  [UNSIGNED32       R_R_R_]      0x00000000 / 0
//     0x0a      "SubIndex 00A"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x0b      "SM Event Missed Counter"                     [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x0c      "Cycle Exceeded Counter"                      [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x0d      "Shift Too Short Counter"                     [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x0e      "SubIndex 00E"                                [UNSIGNED16       R_R_R_]      0x0000 / 0
//     0x0f      "SubIndex 00F"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x10      "SubIndex 010"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x11      "SubIndex 011"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x12      "SubIndex 012"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x13      "SubIndex 013"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x14      "SubIndex 014"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x15      "SubIndex 015"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x16      "SubIndex 016"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x17      "SubIndex 017"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x18      "SubIndex 018"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x19      "SubIndex 019"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x1a      "SubIndex 01A"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x1b      "SubIndex 01B"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x1c      "SubIndex 01C"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x1d      "SubIndex 01D"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x1e      "SubIndex 01E"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x1f      "SubIndex 01F"                                [UNSIGNED16       RWRWRW]      0x0000 / 0
//     0x20      "Sync Error"                                  [UNSIGNED16       R_R_R_]      0x0000 / 0
// 0x2005      "Fast Reference"                              [VAR]
//     0x00      "Fast Reference"                              [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x200a      "Manufacture Boot Version"                    [VAR]
//     0x00      "Manufacture Boot Version"                    [VISIBLE_STR(64)  R_R_R_]      "1.1.3.35""
// 0x201b      "Filtered RMS Current"                        [VAR]
//     0x00      "Filtered RMS Current"                        [REAL32           R_R_R_]      0.009236
// 0x2020      "Homing on block limits"                      [RECORD  maxsub(0x05 / 5)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x05 / 5
//     0x01      "Torque limit"                                [INTEGER16        RWRWRW]      0x0000 / 0
//     0x02      "Time limit"                                  [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x03      "Distance limit in counts"                    [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x04      "Detection Velocity Limit"                    [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x05      "Detection Velocity Time"                     [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x2041      "Timestamp"                                   [VAR]
//     0x00      "Timestamp"                                   [UNSIGNED32       R_R_R_]      0x75b0a0ec / 1974509804
// 0x2046      "DC Clock inhibit time "                      [VAR]
//     0x00      "DC Clock inhibit time "                      [UNSIGNED16       RWRWRW]      0x0000 / 0
// 0x2060      "Parameters Checksum"                         [VAR]
//     0x00      "Parameters Checksum"                         [UNSIGNED32       R_R_R_]      0x7ee316a0 / 2128811680
// 0x2061      "FoE Download Parameters Error"               [VAR]
//     0x00      "FoE Download Parameters Error"               [UNSIGNED16       R_R_R_]      0x0000 / 0
// 0x2062      "FoE Parameters Last String Send To Drive"      [VAR]
//     0x00      "FoE Parameters Last String Send To Drive"      [VISIBLE_STR(512) R_R_R_]      """
// 0x207b      "Auxiliary Position range limit"              [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Min Auxiliary position range limit"          [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x02      "Max Auxiliary position range limit"          [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x2081      "EE Extendend Error"                          [RECORD  maxsub(0x06 / 6)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x06 / 6
//     0x01      "Serial Encoder Error"                        [INTEGER32        R_R_R_]      0x00000000 / 0
//     0x02      "Profiler Data Base Error"                    [INTEGER32        R_R_R_]      0x00000000 / 0
//     0x03      "DL Error"                                    [INTEGER32        R_R_R_]      0x00000000 / 0
//     0x04      "SDO ELMO Format Error"                       [INTEGER32        R_R_R_]      0x00000000 / 0
//     0x05      "MO Failed to start Reason"                   [INTEGER32        R_R_R_]      0x00000000 / 0
//     0x06      "ECAM Error"                                  [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x2084      "Serial Sensor Status Reg"                    [VAR]
//     0x00      "Serial Sensor Status Reg"                    [UNSIGNED16       R_R_R_]      0xb4ba / 46266
// 0x2085      "Extra Status Reg"                            [VAR]
//     0x00      "Extra Status Reg"                            [UNSIGNED16       R_R_R_]      0x0003 / 3
// 0x2086      "STO Status Reg"                              [VAR]
//     0x00      "STO Status Reg"                              [UNSIGNED32       R_R_R_]      0x00050020 / 327712
// 0x2087      "PAL Version"                                 [VAR]
//     0x00      "PAL Version"                                 [UNSIGNED16       R_R_R_]      0x005a / 90
// 0x20a0      "Auxiliary position actual value"             [VAR]
//     0x00      "Auxiliary position actual value"             [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x20b0      "Socket Additional Func"                      [RECORD  maxsub(0x09 / 9)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x09 / 9
//     0x01      "Main position feedback socket (CA[45])"      [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x02      "Speed feedback socket (CA[46])"              [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x03      "Commutation socket (CA[47])"                 [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x04      "Position reference socket (CA[68])"          [UNSIGNED32       RWRWRW]      0x00000000 / 0
//     0x05      "Speed reference socket (CA[69])"             [UNSIGNED32       RWRWRW]      0x00000000 / 0
//     0x06      "Current reference socket (CA[70])"           [UNSIGNED32       RWRWRW]      0x00000000 / 0
//     0x07      "Touch-probe socket (CA[87])"                 [UNSIGNED32       RWRWRW]      0x00000000 / 0
//     0x08      "Homing 402 - capture socket (OV[54])"        [UNSIGNED32       RWRWRW]      0x00000000 / 0
//     0x09      "Additional position socket (CA[79])"         [UNSIGNED32       RWRWRW]      0x00000000 / 0
// 0x20e0      "Ecat alias obj"                              [VAR]
//     0x00      "Ecat alias obj"                              [UNSIGNED16       RWRWRW]      0x0000 / 0
// 0x20fc      "Absolute Sensors Functions"                  [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Clear Absolute Multi Pos"                    [UNSIGNED16       _W_W_W]      
//     0x02      "Reser EnDAT2.2 Error"                        [UNSIGNED16       _W_W_W]      
// 0x20fd      "Clear Digital Inputs"                        [VAR]
//     0x00      "Clear Digital Inputs"                        [UNSIGNED32       RWRWRW]      0x003f0008 / 4128776
// 0x2110      "KI for inner loop"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2111      "KP for inner loop"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2112      "KP for outer loop"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2113      "Vel Filt1 Param 1"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2114      "Vel Filt1 Param 2"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2115      "Vel Filt1 Param 3"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2116      "Vel Filt1 Param 4"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2117      "Vel Filt2 Param 1"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2118      "Vel Filt2 Param 2"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2119      "Vel Filt2 Param 3"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x211a      "Vel Filt2 Param 4"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x211b      "Pos Filt2 Param 1"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x211c      "Pos Filt2 Param 2"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x211d      "Pos Filt2 Param 3"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x211e      "Pos Filt2 Param 4"                           [ARRAY  maxsub(0x3f / 63)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x3f / 63
//     0x01      "SI 1"                                        [REAL32           RWRWRW]      0.000000
//     0x02      "SI 2"                                        [REAL32           RWRWRW]      0.000000
//     0x03      "SI 3"                                        [REAL32           RWRWRW]      0.000000
//     0x04      "SI 4"                                        [REAL32           RWRWRW]      0.000000
//     0x05      "SI 5"                                        [REAL32           RWRWRW]      0.000000
//     0x06      "SI 6"                                        [REAL32           RWRWRW]      0.000000
//     0x07      "SI 7"                                        [REAL32           RWRWRW]      0.000000
//     0x08      "SI 8"                                        [REAL32           RWRWRW]      0.000000
//     0x09      "SI 9"                                        [REAL32           RWRWRW]      0.000000
//     0x0a      "SI 10"                                       [REAL32           RWRWRW]      0.000000
//     0x0b      "SI 11"                                       [REAL32           RWRWRW]      0.000000
//     0x0c      "SI 12"                                       [REAL32           RWRWRW]      0.000000
//     0x0d      "SI 13"                                       [REAL32           RWRWRW]      0.000000
//     0x0e      "SI 14"                                       [REAL32           RWRWRW]      0.000000
//     0x0f      "SI 15"                                       [REAL32           RWRWRW]      0.000000
//     0x10      "SI 16"                                       [REAL32           RWRWRW]      0.000000
//     0x11      "SI 17"                                       [REAL32           RWRWRW]      0.000000
//     0x12      "SI 18"                                       [REAL32           RWRWRW]      0.000000
//     0x13      "SI 19"                                       [REAL32           RWRWRW]      0.000000
//     0x14      "SI 20"                                       [REAL32           RWRWRW]      0.000000
//     0x15      "SI 21"                                       [REAL32           RWRWRW]      0.000000
//     0x16      "SI 22"                                       [REAL32           RWRWRW]      0.000000
//     0x17      "SI 23"                                       [REAL32           RWRWRW]      0.000000
//     0x18      "SI 24"                                       [REAL32           RWRWRW]      0.000000
//     0x19      "SI 25"                                       [REAL32           RWRWRW]      0.000000
//     0x1a      "SI 26"                                       [REAL32           RWRWRW]      0.000000
//     0x1b      "SI 27"                                       [REAL32           RWRWRW]      0.000000
//     0x1c      "SI 28"                                       [REAL32           RWRWRW]      0.000000
//     0x1d      "SI 29"                                       [REAL32           RWRWRW]      0.000000
//     0x1e      "SI 30"                                       [REAL32           RWRWRW]      0.000000
//     0x1f      "SI 31"                                       [REAL32           RWRWRW]      0.000000
//     0x20      "SI 32"                                       [REAL32           RWRWRW]      0.000000
//     0x21      "SI 33"                                       [REAL32           RWRWRW]      0.000000
//     0x22      "SI 34"                                       [REAL32           RWRWRW]      0.000000
//     0x23      "SI 35"                                       [REAL32           RWRWRW]      0.000000
//     0x24      "SI 36"                                       [REAL32           RWRWRW]      0.000000
//     0x25      "SI 37"                                       [REAL32           RWRWRW]      0.000000
//     0x26      "SI 38"                                       [REAL32           RWRWRW]      0.000000
//     0x27      "SI 39"                                       [REAL32           RWRWRW]      0.000000
//     0x28      "SI 40"                                       [REAL32           RWRWRW]      0.000000
//     0x29      "SI 41"                                       [REAL32           RWRWRW]      0.000000
//     0x2a      "SI 42"                                       [REAL32           RWRWRW]      0.000000
//     0x2b      "SI 43"                                       [REAL32           RWRWRW]      0.000000
//     0x2c      "SI 44"                                       [REAL32           RWRWRW]      0.000000
//     0x2d      "SI 45"                                       [REAL32           RWRWRW]      0.000000
//     0x2e      "SI 46"                                       [REAL32           RWRWRW]      0.000000
//     0x2f      "SI 47"                                       [REAL32           RWRWRW]      0.000000
//     0x30      "SI 48"                                       [REAL32           RWRWRW]      0.000000
//     0x31      "SI 49"                                       [REAL32           RWRWRW]      0.000000
//     0x32      "SI 50"                                       [REAL32           RWRWRW]      0.000000
//     0x33      "SI 51"                                       [REAL32           RWRWRW]      0.000000
//     0x34      "SI 52"                                       [REAL32           RWRWRW]      0.000000
//     0x35      "SI 53"                                       [REAL32           RWRWRW]      0.000000
//     0x36      "SI 54"                                       [REAL32           RWRWRW]      0.000000
//     0x37      "SI 55"                                       [REAL32           RWRWRW]      0.000000
//     0x38      "SI 56"                                       [REAL32           RWRWRW]      0.000000
//     0x39      "SI 57"                                       [REAL32           RWRWRW]      0.000000
//     0x3a      "SI 58"                                       [REAL32           RWRWRW]      0.000000
//     0x3b      "SI 59"                                       [REAL32           RWRWRW]      0.000000
//     0x3c      "SI 60"                                       [REAL32           RWRWRW]      0.000000
//     0x3d      "SI 61"                                       [REAL32           RWRWRW]      0.000000
//     0x3e      "SI 62"                                       [REAL32           RWRWRW]      0.000000
//     0x3f      "SI 63"                                       [REAL32           RWRWRW]      0.000000
// 0x2202      "Extended Inputs"                             [RECORD  maxsub(0x03 / 3)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x03 / 3
//     0x01      "Extended Inputs Value"                       [UNSIGNED32       R_R_R_]      0x8b1a9a1a / 2333776410
//     0x02      "Extended Inputs Logic"                       [UNSIGNED32       RWRWRW]      0x00000000 / 0
//     0x03      "Extended Inputs Mask"                        [UNSIGNED32       RWRWRW]      0x00000000 / 0
// 0x2203      "App Object"                                  [VAR]
//     0x00      "App Object"                                  [UNSIGNED32       R_R_R_]      0x00000038 / 56
// 0x2205      "Analog Inputs"                               [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Analog input 1"                              [INTEGER16        R_R_R_]      0x005c / 92
//     0x02      "Analog input 2"                              [INTEGER16        R_R_R_]      0x06ee / 1774
// 0x2206      "Digital Supply In mV"                        [VAR]
//     0x00      "Digital Supply In mV"                        [INTEGER16        R_R_R_]      0x13d7 / 5079
// 0x2207      "Shunt Counter"                               [VAR]
//     0x00      "Shunt Counter"                               [UNSIGNED32       R_R_R_]      0x00000000 / 0
// 0x22a1      "Extended Outputs"                            [RECORD  maxsub(0x03 / 3)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x03 / 3
//     0x01      "Extended Outputs Value"                      [UNSIGNED32       RWRWRW]      0x00000000 / 0
//     0x02      "Extended Outputs Logic"                      [UNSIGNED32       RWRWRW]      0xffffffff / 4294967295
//     0x03      "Extended Outputs Mask"                       [UNSIGNED32       RWRWRW]      0xffffffff / 4294967295
// 0x22a3      "Temperature array"                           [RECORD  maxsub(0x03 / 3)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x03 / 3
//     0x01      "Drive Temperature [C]"                       [INTEGER16        R_R_R_]      0x0038 / 56
//     0x02      "Drive Temperature [F]"                       [INTEGER16        R_R_R_]      0x0084 / 132
//     0x03      "Sensor Temperature"                          [INTEGER16        R_R_R_]      0x0000 / 0
// 0x22a4      "Motor temperature"                           [VAR]
//     0x00      "Motor temperature"                           [INTEGER16        R_R_R_]      0x0000 / 0
// 0x22a5      "Sensor temperature"                          [VAR]
//     0x00      "Sensor temperature"                          [INTEGER16        R_R_R_]      0x0000 / 0
// 0x2e00      "Gain scheduling manual index"                [VAR]
//     0x00      "Gain scheduling manual index"                [UNSIGNED16       RWRWRW]      0x0000 / 0
// 0x2e10      "Set Position On TouchProbe"                  [VAR]
//     0x00      "Set Position On TouchProbe"                  [UNSIGNED16       RWRWRW]      0x0000 / 0
// 0x2e15      "Gantry Yaw Offset"                           [VAR]
//     0x00      "Gantry Yaw Offset"                           [INTEGER16        RWRWRW]      0x0000 / 0
// 0x2f00      "UI[] Commands"                               [ARRAY  maxsub(0x18 / 24)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x18 / 24
//     0x01      "UI[1]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x02      "UI[2]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x03      "UI[3]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x04      "UI[4]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x05      "UI[5]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x06      "UI[6]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x07      "UI[7]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x08      "UI[8]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x09      "UI[9]"                                       [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x0a      "UI[10]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x0b      "UI[11]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x0c      "UI[12]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x0d      "UI[13]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x0e      "UI[14]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x0f      "UI[15]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x10      "UI[16]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x11      "UI[17]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x12      "UI[18]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x13      "UI[19]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x14      "UI[20]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x15      "UI[21]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x16      "UI[22]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x17      "UI[23]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x18      "UI[24]"                                      [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x2f01      "UF[] Commands"                               [ARRAY  maxsub(0x18 / 24)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x18 / 24
//     0x01      "UF[1]"                                       [REAL32           RWRWRW]      0.000000
//     0x02      "UF[2]"                                       [REAL32           RWRWRW]      0.000000
//     0x03      "UF[3]"                                       [REAL32           RWRWRW]      0.000000
//     0x04      "UF[4]"                                       [REAL32           RWRWRW]      0.000000
//     0x05      "UF[5]"                                       [REAL32           RWRWRW]      0.000000
//     0x06      "UF[6]"                                       [REAL32           RWRWRW]      0.000000
//     0x07      "UF[7]"                                       [REAL32           RWRWRW]      0.000000
//     0x08      "UF[8]"                                       [REAL32           RWRWRW]      0.000000
//     0x09      "UF[9]"                                       [REAL32           RWRWRW]      0.000000
//     0x0a      "UF[10]"                                      [REAL32           RWRWRW]      0.000000
//     0x0b      "UF[11]"                                      [REAL32           RWRWRW]      0.000000
//     0x0c      "UF[12]"                                      [REAL32           RWRWRW]      0.000000
//     0x0d      "UF[13]"                                      [REAL32           RWRWRW]      0.000000
//     0x0e      "UF[14]"                                      [REAL32           RWRWRW]      0.000000
//     0x0f      "UF[15]"                                      [REAL32           RWRWRW]      0.000000
//     0x10      "UF[16]"                                      [REAL32           RWRWRW]      0.000000
//     0x11      "UF[17]"                                      [REAL32           RWRWRW]      0.000000
//     0x12      "UF[18]"                                      [REAL32           RWRWRW]      0.000000
//     0x13      "UF[19]"                                      [REAL32           RWRWRW]      0.000000
//     0x14      "UF[20]"                                      [REAL32           RWRWRW]      0.000000
//     0x15      "UF[21]"                                      [REAL32           RWRWRW]      0.000000
//     0x16      "UF[22]"                                      [REAL32           RWRWRW]      0.000000
//     0x17      "UF[23]"                                      [REAL32           RWRWRW]      0.000000
//     0x18      "UF[24]"                                      [REAL32           RWRWRW]      0.000000
// 0x2f05      "Hardware Type"                               [VAR]
//     0x00      "Hardware Type"                               [UNSIGNED16       R_R_R_]      0x0003 / 3
// 0x2f41      "Configuration Object"                        [VAR]
//     0x00      "Configuration Object"                        [UNSIGNED32       RWRWRW]      0x00000000 / 0
// 0x2f45      "Extra Threshold"                             [RECORD  maxsub(0x04 / 4)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x04 / 4
//     0x01      "High voltage level [mV]"                     [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x02      "Low voltage level [mV]"                      [INTEGER32        RWRWRW]      0x000186a0 / 100000
//     0x03      "Analog sensors min amplitude [A2D^2]"        [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x04      "High Temperature sensing [C]"                [INTEGER32        RWRWRW]      0x00000055 / 85
// 0x2f75      "Extrapolation Timeout Cycles"                [VAR]
//     0x00      "Extrapolation Timeout Cycles"                [INTEGER16        RWRWRW]      0x0001 / 1
// 0x6007      "Abort connection code"                       [VAR]
//     0x00      "Abort connection code"                       [INTEGER16        RWRWRW]      0x0001 / 1
// 0x603f      "Error Code"                                  [VAR]
//     0x00      "Error Code"                                  [UNSIGNED16       R_R_R_]      0x0000 / 0
// 0x6040      "Controlword"                                 [VAR]
//     0x00      "Controlword"                                 [UNSIGNED16       RWRWRW]      0x010d / 269
// 0x6041      "Statusword"                                  [VAR]
//     0x00      "Statusword"                                  [UNSIGNED16       R_R_R_]      0x0250 / 592
// 0x605a      "Quick stop option code"                      [VAR]
//     0x00      "Quick stop option code"                      [INTEGER16        RWRWRW]      0x0002 / 2
// 0x605b      "Shutdown option code"                        [VAR]
//     0x00      "Shutdown option code"                        [INTEGER16        RWRWRW]      0x0000 / 0
// 0x605c      "Disable Operation option code"               [VAR]
//     0x00      "Disable Operation option code"               [INTEGER16        RWRWRW]      0x0000 / 0
// 0x605d      "Halt option code"                            [VAR]
//     0x00      "Halt option code"                            [INTEGER16        RWRWRW]      0x0002 / 2
// 0x605e      "Fault reaction option code"                  [VAR]
//     0x00      "Fault reaction option code"                  [INTEGER16        RWRWRW]      0x0000 / 0
// 0x6060      "Modes of operation"                          [VAR]
//     0x00      "Modes of operation"                          [INTEGER8         RWRWRW]      0x04 / 4
// 0x6061      "Modes of operation display"                  [VAR]
//     0x00      "Modes of operation display"                  [INTEGER8         R_R_R_]      0x04 / 4
// 0x6062      "Position demand value"                       [VAR]
//     0x00      "Position demand value"                       [INTEGER32        R_R_R_]      0x0003a419 / 238617
// 0x6063      "Position actual internal value"              [VAR]
//     0x00      "Position actual internal value"              [INTEGER32        R_R_R_]      0x0003b270 / 242288
// 0x6064      "Position actual value"                       [VAR]
//     0x00      "Position actual value"                       [INTEGER32        R_R_R_]      0x0003b270 / 242288
// 0x6065      "Position following error window"             [VAR]
//     0x00      "Position following error window"             [UNSIGNED32       RWRWRW]      0x3b9aca00 / 1000000000
// 0x6066      "Position following error time out"           [VAR]
//     0x00      "Position following error time out"           [UNSIGNED16       RWRWRW]      0x0014 / 20
// 0x6067      "Position window"                             [VAR]
//     0x00      "Position window"                             [UNSIGNED32       RWRWRW]      0x00000064 / 100
// 0x6068      "Position window times"                       [VAR]
//     0x00      "Position window times"                       [UNSIGNED16       RWRWRW]      0x0014 / 20
// 0x6069      "Velocity sensor actual value"                [VAR]
//     0x00      "Velocity sensor actual value"                [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x606a      "Velocity sensor selection code"              [VAR]
//     0x00      "Velocity sensor selection code"              [INTEGER16        RWRWRW]      0x0001 / 1
// 0x606b      "Velocity demand value"                       [VAR]
//     0x00      "Velocity demand value"                       [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x606c      "Velocity actual value"                       [VAR]
//     0x00      "Velocity actual value"                       [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x606d      "Velocity Window"                             [VAR]
//     0x00      "Velocity Window"                             [UNSIGNED16       RWRWRW]      0x0064 / 100
// 0x606e      "Velocity Window time"                        [VAR]
//     0x00      "Velocity Window time"                        [UNSIGNED16       RWRWRW]      0x0014 / 20
// 0x606f      "Velocity threshold"                          [VAR]
//     0x00      "Velocity threshold"                          [UNSIGNED16       RWRWRW]      0x0064 / 100
// 0x6070      "Velocity threshold time"                     [VAR]
//     0x00      "Velocity threshold time"                     [UNSIGNED16       RWRWRW]      0x0014 / 20
// 0x6071      "Target torque"                               [VAR]
//     0x00      "Target torque"                               [INTEGER16        RWRWRW]      0x0190 / 400
// 0x6072      "Maximal torque"                              [VAR]
//     0x00      "Maximal torque"                              [UNSIGNED16       RWRWRW]      0x03e8 / 1000
// 0x6073      "Maximal Current"                             [VAR]
//     0x00      "Maximal Current"                             [UNSIGNED16       RWRWRW]      0x03e8 / 1000
// 0x6074      "Torque demand"                               [VAR]
//     0x00      "Torque demand"                               [INTEGER16        R_R_R_]      0x0000 / 0
// 0x6075      "Motor rated current"                         [VAR]
//     0x00      "Motor rated current"                         [UNSIGNED32       RWRWRW]      0x00000b0e / 2830
// 0x6076      "Motor rated torque"                          [VAR]
//     0x00      "Motor rated torque"                          [UNSIGNED32       RWRWRW]      0x00000b0e / 2830
// 0x6077      "Torque value"                                [VAR]
//     0x00      "Torque value"                                [INTEGER16        R_R_R_]      0x0000 / 0
// 0x6078      "Current actual value"                        [VAR]
//     0x00      "Current actual value"                        [INTEGER16        R_R_R_]      0x0000 / 0
// 0x6079      "DC link voltage"                             [VAR]
//     0x00      "DC link voltage"                             [UNSIGNED32       R_R_R_]      0x00005f46 / 24390
// 0x607a      "Target position"                             [VAR]
//     0x00      "Target position"                             [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x607b      "Position range limit"                        [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Min position range limit"                    [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x02      "Max position range limit"                    [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x607c      "Home offset"                                 [VAR]
//     0x00      "Home offset"                                 [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x607d      "Software Position limit"                     [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Min position limit"                          [INTEGER32        RWRWRW]      0x00000000 / 0
//     0x02      "Max position limit"                          [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x607e      "Polarity"                                    [VAR]
//     0x00      "Polarity"                                    [UNSIGNED8        RWRWRW]      0x00 / 0
// 0x607f      "Max profile velocity"                        [VAR]
//     0x00      "Max profile velocity"                        [UNSIGNED32       RWRWRW]      0x00001f40 / 8000
// 0x6080      "Max motor speed"                             [VAR]
//     0x00      "Max motor speed"                             [UNSIGNED32       RWRWRW]      0xffffffff / 4294967295
// 0x6081      "Profile velocity"                            [VAR]
//     0x00      "Profile velocity"                            [UNSIGNED32       RWRWRW]      0x7fffffff / 2147483647
// 0x6082      "End velocity"                                [VAR]
//     0x00      "End velocity"                                [UNSIGNED32       RWRWRW]      0x00000000 / 0
// 0x6083      "Profile acceleration"                        [VAR]
//     0x00      "Profile acceleration"                        [UNSIGNED32       RWRWRW]      0x7fffffff / 2147483647
// 0x6084      "Profile deceleration"                        [VAR]
//     0x00      "Profile deceleration"                        [UNSIGNED32       RWRWRW]      0x7fffffff / 2147483647
// 0x6085      "Quick stop deceleration"                     [VAR]
//     0x00      "Quick stop deceleration"                     [UNSIGNED32       RWRWRW]      0x7fffffff / 2147483647
// 0x6086      "Motion profile type"                         [VAR]
//     0x00      "Motion profile type"                         [INTEGER16        RWRWRW]      0x0000 / 0
// 0x6087      "Torque slope"                                [VAR]
//     0x00      "Torque slope"                                [UNSIGNED32       RWRWRW]      0x00000064 / 100
// 0x608f      "Position encoder resolution"                 [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Encoder increments"                          [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x02      "Motor revolutions"                           [UNSIGNED32       RWRWRW]      0x00000001 / 1
// 0x6090      "Velocity encoder resolution"                 [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Encoder increments per second"               [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x02      "Motor revolutions per second"                [UNSIGNED32       RWRWRW]      0x00000001 / 1
// 0x6091      "Gear ratio"                                  [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Motor revolutions"                           [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x02      "Shaft revolutions"                           [UNSIGNED32       RWRWRW]      0x00000001 / 1
// 0x6092      "Feed constant"                               [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Feed"                                        [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x02      "Shaft revolutions"                           [UNSIGNED32       RWRWRW]      0x00000001 / 1
// 0x6096      "Velocity factor"                             [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Numerator"                                   [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x02      "Divisor"                                     [UNSIGNED32       RWRWRW]      0x00000001 / 1
// 0x6097      "Acceleration factor"                         [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Numerator"                                   [UNSIGNED32       RWRWRW]      0x00000001 / 1
//     0x02      "Divisor"                                     [UNSIGNED32       RWRWRW]      0x00000001 / 1
// 0x6098      "Homing method"                               [VAR]
//     0x00      "Homing method"                               [INTEGER8         RWRWRW]      0x01 / 1
// 0x6099      "Homing speeds"                               [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Speed during search for switch"              [UNSIGNED32       RWRWRW]      0x000003e8 / 1000
//     0x02      "Speed during search for zero"                [UNSIGNED32       RWRWRW]      0x000003e8 / 1000
// 0x609a      "Homing Acceleration"                         [VAR]
//     0x00      "Homing Acceleration"                         [UNSIGNED32       RWRWRW]      0x000f4240 / 1000000
// 0x60b0      "Position offset"                             [VAR]
//     0x00      "Position offset"                             [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x60b1      "Velocity offset"                             [VAR]
//     0x00      "Velocity offset"                             [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x60b2      "Torque offset"                               [VAR]
//     0x00      "Torque offset"                               [INTEGER16        RWRWRW]      0x0000 / 0
// 0x60b8      "Touch probe function"                        [VAR]
//     0x00      "Touch probe function"                        [UNSIGNED16       RWRWRW]      0x0000 / 0
// 0x60b9      "Touch probe status"                          [VAR]
//     0x00      "Touch probe status"                          [UNSIGNED16       R_R_R_]      0x0000 / 0
// 0x60ba      "Touch probe pos1 pos value"                  [VAR]
//     0x00      "Touch probe pos1 pos value"                  [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x60bb      "Touch probe pos1 neg value"                  [VAR]
//     0x00      "Touch probe pos1 neg value"                  [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x60bc      "Touch probe pos2 pos value"                  [VAR]
//     0x00      "Touch probe pos2 pos value"                  [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x60bd      "Touch probe pos2 neg value"                  [VAR]
//     0x00      "Touch probe pos2 neg value"                  [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x60c2      "Interpolation time period"                   [RECORD  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Interpolation time period value"             [UNSIGNED8        RWRWRW]      0x01 / 1
//     0x02      "Interpolation time index"                    [INTEGER8         RWRWRW]      0xfffffffd / -3
// 0x60c5      "Max acceleration"                            [VAR]
//     0x00      "Max acceleration"                            [UNSIGNED32       RWRWRW]      0x7fffffff / 2147483647
// 0x60c6      "Max deceleration"                            [VAR]
//     0x00      "Max deceleration"                            [UNSIGNED32       RWRWRW]      0x7fffffff / 2147483647
// 0x60e3      "Supported Homing Method"                     [ARRAY  maxsub(0x24 / 36)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x24 / 36
//     0x01      "1"                                           [INTEGER8         R_R_R_]      0x01 / 1
//     0x02      "2"                                           [INTEGER8         R_R_R_]      0x02 / 2
//     0x03      "3"                                           [INTEGER8         R_R_R_]      0x03 / 3
//     0x04      "4"                                           [INTEGER8         R_R_R_]      0x04 / 4
//     0x05      "5"                                           [INTEGER8         R_R_R_]      0x05 / 5
//     0x06      "6"                                           [INTEGER8         R_R_R_]      0x06 / 6
//     0x07      "7"                                           [INTEGER8         R_R_R_]      0x07 / 7
//     0x08      "8"                                           [INTEGER8         R_R_R_]      0x08 / 8
//     0x09      "9"                                           [INTEGER8         R_R_R_]      0x09 / 9
//     0x0a      "10"                                          [INTEGER8         R_R_R_]      0x0a / 10
//     0x0b      "11"                                          [INTEGER8         R_R_R_]      0x0b / 11
//     0x0c      "12"                                          [INTEGER8         R_R_R_]      0x0c / 12
//     0x0d      "13"                                          [INTEGER8         R_R_R_]      0x0d / 13
//     0x0e      "14"                                          [INTEGER8         R_R_R_]      0x0e / 14
//     0x0f      "15"                                          [INTEGER8         R_R_R_]      0x11 / 17
//     0x10      "16"                                          [INTEGER8         R_R_R_]      0x12 / 18
//     0x11      "17"                                          [INTEGER8         R_R_R_]      0x13 / 19
//     0x12      "18"                                          [INTEGER8         R_R_R_]      0x14 / 20
//     0x13      "19"                                          [INTEGER8         R_R_R_]      0x15 / 21
//     0x14      "20"                                          [INTEGER8         R_R_R_]      0x16 / 22
//     0x15      "21"                                          [INTEGER8         R_R_R_]      0x17 / 23
//     0x16      "22"                                          [INTEGER8         R_R_R_]      0x18 / 24
//     0x17      "23"                                          [INTEGER8         R_R_R_]      0x19 / 25
//     0x18      "24"                                          [INTEGER8         R_R_R_]      0x1a / 26
//     0x19      "25"                                          [INTEGER8         R_R_R_]      0x1b / 27
//     0x1a      "26"                                          [INTEGER8         R_R_R_]      0x1c / 28
//     0x1b      "27"                                          [INTEGER8         R_R_R_]      0x1d / 29
//     0x1c      "28"                                          [INTEGER8         R_R_R_]      0x1e / 30
//     0x1d      "29"                                          [INTEGER8         R_R_R_]      0x21 / 33
//     0x1e      "30"                                          [INTEGER8         R_R_R_]      0x22 / 34
//     0x1f      "31"                                          [INTEGER8         R_R_R_]      0x23 / 35
//     0x20      "32"                                          [INTEGER8         R_R_R_]      0xfffffffe / -2
//     0x21      "33"                                          [INTEGER8         R_R_R_]      0xffffffff / -1
//     0x22      "34"                                          [INTEGER8         R_R_R_]      0xfffffffc / -4
//     0x23      "35"                                          [INTEGER8         R_R_R_]      0xfffffffd / -3
//     0x24      "36"                                          [INTEGER8         R_R_R_]      0x25 / 37
// 0x60f2      "Positioning option code"                     [VAR]
//     0x00      "Positioning option code"                     [UNSIGNED16       RWRWRW]      0x0000 / 0
// 0x60f4      "Following error actual value"                [VAR]
//     0x00      "Following error actual value"                [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x60fa      "Control effort"                              [VAR]
//     0x00      "Control effort"                              [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x60fc      "Position demand internal value"              [VAR]
//     0x00      "Position demand internal value"              [INTEGER32        R_R_R_]      0x00000000 / 0
// 0x60fd      "Digital inputs"                              [VAR]
//     0x00      "Digital inputs"                              [UNSIGNED32       R_R_R_]      0x003f0008 / 4128776
// 0x60fe      "Digital Outputs"                             [ARRAY  maxsub(0x02 / 2)]
//     0x00      "Number of sub indexes"                       [UNSIGNED8        R_R_R_]      0x02 / 2
//     0x01      "Physical outputs"                            [UNSIGNED32       RWRWRW]      0x00000000 / 0
//     0x02      "Bit mask"                                    [UNSIGNED32       RWRWRW]      0x00000000 / 0
// 0x60ff      "Target velocity"                             [VAR]
//     0x00      "Target velocity"                             [INTEGER32        RWRWRW]      0x00000000 / 0
// 0x6502      "Supported drive modes"                       [VAR]
//     0x00      "Supported drive modes"                       [UNSIGNED32       R_R_R_]      0x000003ed / 1005
// End slaveinfo, close socket
// End program


#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include "soem/soem.h"
#include <signal.h>

#define EC_TIMEOUTMON 500

static char IOmap[4096];
static ecx_contextt ctx;
char ifname[] = "enp86s0";  // Change to your NIC
uint8_t slave = 1;
uint16_t status_word_mask = 0x006F; // 0000 0000 0110 1111
uint16_t sw;

volatile int run = 1;
void stop_handler(int sig) { run = 0; }

// Control word bit definitions
    enum controlword_bit{
        control_bit_switch_on = 0,
        control_bit_enable_voltage = 1,
        control_bit_quick_stop = 2,
        control_bit_enable_operation = 3,
        control_bit_fault_reset = 7,
        control_bit_homing = 4,
        control_bit_5 = 5,
        control_bit_6 = 6,
        control_bit_halt = 8
    };

    // CIA-402 State Definitions with bit values
    enum statusword_state{
        Not_ready_to_switch_on = 0x0,
        Switch_on_disabled = 1 << 6,
        Ready_to_switch_on = (1 << 5) | 1,
        Switch_on = (1 << 5) | 3,
        Operation_enabled = (1 << 5) | 7,
        Quick_stop_active = 0x7,
        Fault_reaction_active = 0x0f,
        Fault = 1 << 3,
        Target_reached = 1 << 10,
        Home_found = 1 << 12,
        Homing_error = 1 << 13,
    };


// TxPDO
int32_t *position_actual_value;                    // Position actual value;
int32_t *position_following_error_actual_value;    // Position Following error actual value;
int16_t *torque_actual_value;                       // Torque actual value;
uint16_t *status_word;                             // Status word;
int8_t *operation_mode_display;                   // Mode of operation display;
// RxPDO
int32_t *target_position;                         // Target Position;
int32_t *target_velocity;                         // Target Velocity;
int16_t *target_torque;                            // Target Torque;
uint16_t *max_torque;                             // Max Torque;
uint16_t *control_word;                           // Control word;
int8_t *operation_mode;                          // Mode of operation;

void mapMappedPDOparameters()
{
     // TxPDO
    position_actual_value = (int32_t *)(ctx.slavelist[1].inputs + 0);                    // Position actual value;
    position_following_error_actual_value = (int32_t *)(ctx.slavelist[1].inputs + 4);    // Position Following error actual value;
    torque_actual_value = (int16_t *)(ctx.slavelist[1].inputs + 8);                       // Torque actual value;
    status_word = (uint16_t *)(ctx.slavelist[1].inputs + 10);                             // Status word;
    operation_mode_display = (int8_t *)(ctx.slavelist[1].inputs + 12);                   // Mode of operation display;
    // RxPDO
    target_position = (int32_t *)(ctx.slavelist[1].outputs + 0);                         // Target Position;
    target_velocity = (int32_t *)(ctx.slavelist[1].outputs + 4);                         // Target Velocity;
    target_torque = (int16_t *)(ctx.slavelist[1].outputs + 8);                            // Target Torque;
    max_torque = (uint16_t *)(ctx.slavelist[1].outputs + 10);                             // Max Torque;
    control_word = (uint16_t *)(ctx.slavelist[1].outputs + 12);                           // Control word;
    operation_mode = (int8_t *)(ctx.slavelist[1].outputs + 14);                          // Mode of operation;
}

// void setModeHoming(){

//     //Configure Homing Parameters
//     uint8_t homing_method = 35;   // example: index pulse / halls method
//     int32_t homing_offset = 0;

//     ecx_SDOwrite(&ctx,slave,0x6098,0,FALSE,1,&homing_method,EC_TIMEOUTRXM);
//     ecx_SDOwrite(&ctx,1,0x607C,0,FALSE,4,&homing_offset,EC_TIMEOUTRXM);

//     //Switch to Homing mode
//     uint8_t mode = 6;  // Homing mode
//     int mode_size = sizeof(mode);
//     ecx_SDOwrite(&ctx,slave,0x6060,0,FALSE,mode_size,&mode,EC_TIMEOUTRXM);

// }

// void setModeProfilePosition(){
//     uint8_t mode = 1; // Profile Position mode
//     int mode_size = sizeof(mode);
//     ecx_SDOwrite(&ctx,slave,0x6060,0,FALSE,mode_size,&mode,EC_TIMEOUTRXM);

//     //Enable Software Position limits
//     int32_t sw_min = -100000;
//     int32_t sw_max =  100000;
//     int sw_min_size = sizeof(sw_min);
//     int sw_max_size = sizeof(sw_max);

//     ecx_SDOwrite(&ctx, slave, 0x607D, 1, FALSE,
//                 sw_min_size, &sw_min, EC_TIMEOUTRXM);

//     ecx_SDOwrite(&ctx, slave, 0x607D, 2, FALSE,
//                 sw_max_size, &sw_max, EC_TIMEOUTRXM);
// }

void setModeProfileTorque(){

    // Here only write to SDOs which are not in your TxPDOs, and RxPDOs
    uint8_t mode = 4; // Profile Torque mode
    int mode_size = sizeof(mode);
    ecx_SDOwrite(&ctx,slave,0x6060,0,FALSE,mode_size,&mode,EC_TIMEOUTRXM);

    // // Set Motor rated current (Not required as it is already mapped through tuning in EAS II)
    // uint32_t motor_rated_current = 2500;
    // int motor_rated_current_size = sizeof(motor_rated_current);
    // ecx_SDOwrite(&ctx, slave, 0x6075, 0, FALSE, motor_rated_current_size, &motor_rated_current, EC_TIMEOUTRXM);

    // // Set Motor rated torque (Not required as it is already mapped through tuning in EAS II)
    // uint32_t motor_rated_torque = 128;
    // int motor_rated_torque_size = sizeof(motor_rated_torque);
    // ecx_SDOwrite(&ctx, slave, 0x6076, 0, FALSE, motor_rated_torque_size, &motor_rated_torque, EC_TIMEOUTRXM);

    // Set Max Current
    int16_t max_current = 1000;
    int max_current_size = sizeof(max_current);
    ecx_SDOwrite(&ctx, slave, 0x6073, 0, FALSE, max_current_size, &max_current, EC_TIMEOUTRXM);

    // Set Max Torque
    // int16_t max_torque_value = 1000; // 100% of rated
    // int max_torque_value_size = sizeof(max_torque_value);
    // ecx_SDOwrite(&ctx, slave, 0x6072, 0, FALSE, max_torque_value_size, &max_torque_value, EC_TIMEOUTRXM);

    // Set Torque slope
    uint32_t torque_slope = 100;
    int torque_slope_size = sizeof(torque_slope);
    ecx_SDOwrite(&ctx, slave, 0x6087, 0, FALSE, torque_slope_size, &torque_slope, EC_TIMEOUTRXM);

}

// Function showing the State machine transition according to cia-402 to enable the slave in operational mode
void set_slave_operational(){

    int index = 0;
    while (index < 20){
        ecx_send_processdata(&ctx);
        ecx_receive_processdata(&ctx, EC_TIMEOUTRET);

        //Perform masking on the status work to know the current state (Current State is reflected in bits {6, 5, 3, 2, 1, 0})
        sw = *status_word & status_word_mask;
    
        switch(sw){
            case (Not_ready_to_switch_on): {
                /* Now the FSM should automatically go to Switch_on_disabled*/
                printf("Not ready to swtich on\n");
                break;
            }
            case (Switch_on_disabled): {
                /* Automatic transition (2)*/
                *control_word = 0;
                *control_word |= (1 << control_bit_enable_voltage)
                        | (1 << control_bit_quick_stop);
                printf("Switch_on_disabled\n");
                break;
            }
            case (Ready_to_switch_on): {
                /* Switch on command for transition (3) */
                *control_word |= 1 << control_bit_switch_on;
                printf("Ready_to_switch_on\n");
                break;
            }
            case (Switch_on): {
                /* Enable operation command for transition (4) */
                *control_word |= 1 << control_bit_enable_operation;
                printf("Switch_on\n");
                break;
            }
            case (Operation_enabled): {
                printf("Operation_enabled\n");
                break;
            }
            case (Quick_stop_active): {
                printf("Quick_stop_active\n");
                break;
            }
            case (Fault_reaction_active): {
                printf("Fault_reaction_active\n");
                break;
            }
            case (Fault): {
                /* Returning to Switch on Disabled */
                *control_word = (1 << control_bit_fault_reset);
                printf("Fault\n");
                break;
            }
            default:{
                //OSEE_PRINT("Unrecognized status\n");
                printf("Unrecognized\n");
                break;
            }
        }
        
        osal_usleep(10000); // 10ms cycle
        index++;       
    }
}

// void perform_drive_homing(){
//     // Start Homing 
//     //(Control Word Bit 8 (Halt) must be low. A high will cause the homing to stop;bringing it low again will cause the homing to restart)
//     *control_word = 0;
//     *control_word |= 1 << control_bit_homing;

//     bool homing_not_finished = true;

//     while (homing_not_finished)
//     {
//         ecx_send_processdata(&ctx);
//         ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
//         sw = *status_word & status_word_mask;

//         switch (sw)
//         {
//             case (Home_found):{
//                 printf("Home_found\n");
//                 break;   
//             }
//             case (Target_reached):{
//                 printf("Target_reached\n");
//                 homing_not_finished = false;
//                 //Clear bit 4
//                 *control_word &= ~(1 << 4);
//                 ecx_send_processdata(&ctx);
//                 ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
//                 break;   
//             }
//             case (Homing_error):{
//                 printf("Homing_error\n");
//                 break;   
//             }       
                    
//             default:{
//                 break;
//             }
//         }
//     }

// }
void perform_drive_profile_torque(){
    // Set Commanding Torque
    *target_torque = 400;
    // Set max torque
    *max_torque = 1000;
    *control_word &= ~(1 << control_bit_halt);
    bool torque_not_reached = true;
    while (torque_not_reached)
    {
        ecx_send_processdata(&ctx);
        ecx_receive_processdata(&ctx, EC_TIMEOUTRET);

        if (*status_word & (1 << 10)) {
            printf("Target_reached\n");
            torque_not_reached = false;
         }
    }
    
}


int main() {

    signal(SIGINT, stop_handler);
    printf("Starting SOEM with default PDO control...\n");

    // Initialize SOEM
    if (!ecx_init(&ctx, ifname)) {
        printf("Failed to initialize interface %s\n", ifname);
        return -1;
    }
    printf("ekhane\n");

    // Find and configure slaves
    if (ecx_config_init(&ctx) <= 0) {
        printf("No slaves found\n");
        ecx_close(&ctx);
        return -1;
    }

    printf("%d slave(s) found.\n", ctx.slavecount);
    if (ctx.slavecount < 1) {
        ecx_close(&ctx);
        return -1;
    }

     // Go to INIT state
    ctx.slavelist[1].state = EC_STATE_INIT;
    ecx_writestate(&ctx, 1);
    ecx_statecheck(&ctx, 1, EC_STATE_INIT, EC_TIMEOUTSTATE);

    if (ctx.slavelist[1].state != EC_STATE_INIT)
    {
        printf("Slave 1 failed to reach INIT\n");
        ecx_close(&ctx);
        return -1;
    }

    // Go to PRE-OP state
    ctx.slavelist[1].state = EC_STATE_PRE_OP;
    ecx_writestate(&ctx, 1);
    ecx_statecheck(&ctx, 1, EC_STATE_PRE_OP, EC_TIMEOUTSTATE);

    if (ctx.slavelist[1].state != EC_STATE_PRE_OP)
    {
        printf("Slave 1 failed to reach PRE-OP\n");
        ecx_close(&ctx);
        return -1;
    }

    osal_usleep(10000); // 10ms cycle

    // Map PDOs for the slave
    // Sync Manager for TxPDOs
    uint8 tx_zero = 0;
    ecx_SDOwrite(&ctx, slave, 0x1C13, 0, FALSE, 1, &tx_zero, EC_TIMEOUTRXM);
    
    uint16 tx_pdo = 0x1A04;
    ecx_SDOwrite(&ctx,slave, 0x1C13, 1, FALSE, 2, &tx_pdo, EC_TIMEOUTRXM);

    osal_usleep(10000); // 10ms cycle

    uint8 tx_one = 1;
    ecx_SDOwrite(&ctx,slave, 0x1C13, 0, FALSE, 1, &tx_one, EC_TIMEOUTRXM);

    // Sync Manager for RxPDO
    uint8 rx_zero = 0;
    ecx_SDOwrite(&ctx, slave, 0x1C12, 0, FALSE, 1, &rx_zero, EC_TIMEOUTRXM);
    
    uint16 rx_pdo = 0x1605;
    ecx_SDOwrite(&ctx, slave, 0x1C12, 1, FALSE, 2, &rx_pdo, EC_TIMEOUTRXM);
    osal_usleep(10000); // 10ms cycle

    uint8 rx_one = 1;
    ecx_SDOwrite(&ctx, slave, 0x1C12, 0, FALSE, 1, &rx_one, EC_TIMEOUTRXM);

    // Map PDOs
    ec_groupt *group = &ctx.grouplist[0];
    ecx_config_map_group(&ctx, IOmap, 0);

    // Configure Distributed Clocks (if supported)
    ecx_configdc(&ctx);

    osal_usleep(100000); // 10ms cycle

    // Map pointers to the default PDO offsets
    mapMappedPDOparameters();

    // Set Profile Torque mode
    setModeProfileTorque();

    // Put the slave in safe-op state
    ctx.slavelist[1].state = EC_STATE_SAFE_OP;
    ecx_writestate(&ctx, 1);
    ecx_statecheck(&ctx, 1, EC_STATE_SAFE_OP, EC_TIMEOUTSTATE);


    if (ctx.slavelist[1].state != EC_STATE_SAFE_OP)
    {
        printf("Slave 1 failed to reach SAFE-OP\n");
        ecx_close(&ctx);
        return -1;
    }

    ecx_send_processdata(&ctx);
    ecx_receive_processdata(&ctx, EC_TIMEOUTRET);

    // Put the slave in OPERATIONAL state (After this state is enabled, PDO exchanging starts happening)
    ctx.slavelist[1].state = EC_STATE_OPERATIONAL;
    ecx_writestate(&ctx, 1);
    ecx_statecheck(&ctx, 1, EC_STATE_OPERATIONAL, EC_TIMEOUTSTATE);

    if (ctx.slavelist[1].state != EC_STATE_OPERATIONAL) {
        printf("Slave 1 failed to reach OPERATIONAL\n");
        ecx_close(&ctx);
        return -1;
    }

    printf("Slave 1 in OPERATIONAL state.\n");

    osal_usleep(10000); // 10ms cycle

    // Set the slave in operational mode
    set_slave_operational();

    //Start Commanding torque
    perform_drive_profile_torque();

    // Main cyclic loop
    int index = 0;
    
    while (run) {
        
        ecx_send_processdata(&ctx);
        ecx_receive_processdata(&ctx, EC_TIMEOUTRET);

        if (index == 200) {  // print diagnostics every 200 cycles (~2s)
            printf("Torque commanded: %d\n", *target_torque);
            printf("Torque Act: %d\n", *torque_actual_value);
            printf("Statusword: %d\n", *status_word);
            printf("Ctrl Wrd: %d\n", *control_word);
            printf("Operation mode: %d\n", *operation_mode_display);
            index = 0;
        }
        index++;

        osal_usleep(10000); // 10ms cycle
    }

    *control_word |= (1 << control_bit_halt); // Stop commanding torque to the motor

    for (int i = 0; i < 10; i++) {
        ecx_send_processdata(&ctx);
        ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
        osal_usleep(1000);
    }

    // Move to Switch_on_disabled state
    *control_word &= ~(1 << control_bit_enable_voltage);
    *control_word &= ~(1 << control_bit_fault_reset);

    for (int i = 0; i < 10; i++) {
        ecx_send_processdata(&ctx);
        ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
        osal_usleep(1000);
    }
    sw = *status_word & status_word_mask;

    if (sw == Switch_on_disabled){
        printf("Switch_on_disabled\n");
    }
    osal_usleep(10000); // 10ms cycle

    ecx_close(&ctx);
    
    return 0;
}
