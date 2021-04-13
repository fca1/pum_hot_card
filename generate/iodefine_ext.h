/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F107DE.DVF                                                     */
/*    V1.21 (2013/07/30)                                                */
/*    Copyright(C) 2013 Renesas                                         */
/* Tool Version: 4.0.0                                                  */
/* Date Generated: 2020/01/17                                           */
/************************************************************************/

#ifndef __INTRINSIC_FUNCTIONS
#define __INTRINSIC_FUNCTIONS

#define DI() asm("di")
#define EI() asm("ei")
#define HALT() asm("halt")
#define NOP() asm("nop")
#define STOP() asm("stop")

#endif

#ifndef __IOREG_BIT_STRUCTURES
#define __IOREG_BIT_STRUCTURES
typedef struct {
	unsigned char no0 :1;
	unsigned char no1 :1;
	unsigned char no2 :1;
	unsigned char no3 :1;
	unsigned char no4 :1;
	unsigned char no5 :1;
	unsigned char no6 :1;
	unsigned char no7 :1;
} __BITS8;

typedef struct {
	unsigned short no0 :1;
	unsigned short no1 :1;
	unsigned short no2 :1;
	unsigned short no3 :1;
	unsigned short no4 :1;
	unsigned short no5 :1;
	unsigned short no6 :1;
	unsigned short no7 :1;
	unsigned short no8 :1;
	unsigned short no9 :1;
	unsigned short no10 :1;
	unsigned short no11 :1;
	unsigned short no12 :1;
	unsigned short no13 :1;
	unsigned short no14 :1;
	unsigned short no15 :1;
} __BITS16;

#endif

#ifndef IODEFINE_EXT_H
#define IODEFINE_EXT_H

/*
 IO Registers
 */
union un_adm2 {
	unsigned char adm2;
	__BITS8 BIT;
};
union un_pu0 {
	unsigned char pu0;
	__BITS8 BIT;
};
union un_pu1 {
	unsigned char pu1;
	__BITS8 BIT;
};
union un_pu3 {
	unsigned char pu3;
	__BITS8 BIT;
};
union un_pu4 {
	unsigned char pu4;
	__BITS8 BIT;
};
union un_pu7 {
	unsigned char pu7;
	__BITS8 BIT;
};
union un_pu12 {
	unsigned char pu12;
	__BITS8 BIT;
};
union un_pu14 {
	unsigned char pu14;
	__BITS8 BIT;
};
union un_pim0 {
	unsigned char pim0;
	__BITS8 BIT;
};
union un_pim1 {
	unsigned char pim1;
	__BITS8 BIT;
};
union un_pom0 {
	unsigned char pom0;
	__BITS8 BIT;
};
union un_pom1 {
	unsigned char pom1;
	__BITS8 BIT;
};
union un_pmc0 {
	unsigned char pmc0;
	__BITS8 BIT;
};
union un_pmc12 {
	unsigned char pmc12;
	__BITS8 BIT;
};
union un_pmc14 {
	unsigned char pmc14;
	__BITS8 BIT;
};
union un_nfen0 {
	unsigned char nfen0;
	__BITS8 BIT;
};
union un_nfen1 {
	unsigned char nfen1;
	__BITS8 BIT;
};
union un_isc {
	unsigned char isc;
	__BITS8 BIT;
};
union un_dflctl {
	unsigned char dflctl;
	__BITS8 BIT;
};
union un_mduc {
	unsigned char mduc;
	__BITS8 BIT;
};
union un_per0 {
	unsigned char per0;
	__BITS8 BIT;
};
union un_rmc {
	unsigned char rmc;
	__BITS8 BIT;
};
union un_rpectl {
	unsigned char rpectl;
	__BITS8 BIT;
};
union un_se0l {
	unsigned char se0l;
	__BITS8 BIT;
};
union un_ss0l {
	unsigned char ss0l;
	__BITS8 BIT;
};
union un_st0l {
	unsigned char st0l;
	__BITS8 BIT;
};
union un_soe0l {
	unsigned char soe0l;
	__BITS8 BIT;
};
union un_te0l {
	unsigned char te0l;
	__BITS8 BIT;
};
union un_ts0l {
	unsigned char ts0l;
	__BITS8 BIT;
};
union un_tt0l {
	unsigned char tt0l;
	__BITS8 BIT;
};
union un_toe0l {
	unsigned char toe0l;
	__BITS8 BIT;
};
union un_iicctl00 {
	unsigned char iicctl00;
	__BITS8 BIT;
};
union un_iicctl01 {
	unsigned char iicctl01;
	__BITS8 BIT;
};
union un_crc0ctl {
	unsigned char crc0ctl;
	__BITS8 BIT;
};
union un_p20 {
	unsigned char p20;
	__BITS8 BIT;
};
union un_per1 {
	unsigned char per1;
	__BITS8 BIT;
};
union un_per2 {
	unsigned char per2;
	__BITS8 BIT;
};
union un_pllctl {
	unsigned char pllctl;
	__BITS8 BIT;
};
union un_pm20 {
	unsigned char pm20;
	__BITS8 BIT;
};
union un_egp2 {
	unsigned char egp2;
	__BITS8 BIT;
};
union un_egn2 {
	unsigned char egn2;
	__BITS8 BIT;
};
union un_pu20 {
	unsigned char pu20;
	__BITS8 BIT;
};
union un_pom20 {
	unsigned char pom20;
	__BITS8 BIT;
};
union un_pgactl {
	unsigned char pgactl;
	__BITS8 BIT;
};
union un_c0ctl {
	unsigned char c0ctl;
	__BITS8 BIT;
};
union un_c1ctl {
	unsigned char c1ctl;
	__BITS8 BIT;
};
union un_c2ctl {
	unsigned char c2ctl;
	__BITS8 BIT;
};
union un_c3ctl {
	unsigned char c3ctl;
	__BITS8 BIT;
};
union un_c4ctl {
	unsigned char c4ctl;
	__BITS8 BIT;
};
union un_c5ctl {
	unsigned char c5ctl;
	__BITS8 BIT;
};
union un_cmpegp0 {
	unsigned char cmpegp0;
	__BITS8 BIT;
};
union un_cmpegn0 {
	unsigned char cmpegn0;
	__BITS8 BIT;
};
union un_cmpmon {
	unsigned char cmpmon;
	__BITS8 BIT;
};
union un_intpctl {
	unsigned char intpctl;
	__BITS8 BIT;
};
union un_cvrctl {
	unsigned char cvrctl;
	__BITS8 BIT;
};
union un_cmpwdc {
	unsigned char cmpwdc;
	__BITS8 BIT;
};
union un_se4l {
	unsigned char se4l;
	__BITS8 BIT;
};
union un_ss4l {
	unsigned char ss4l;
	__BITS8 BIT;
};
union un_st4l {
	unsigned char st4l;
	__BITS8 BIT;
};
union un_soe4l {
	unsigned char soe4l;
	__BITS8 BIT;
};
union un_nfen3 {
	unsigned char nfen3;
	__BITS8 BIT;
};
union un_intmk0 {
	unsigned char intmk0;
	__BITS8 BIT;
};
union un_intmf0 {
	unsigned char intmf0;
	__BITS8 BIT;
};
union un_pfsel0 {
	unsigned char pfsel0;
	__BITS8 BIT;
};
union un_suctl {
	unsigned char suctl;
	__BITS8 BIT;
};
union un_toetkc0 {
	unsigned char toetkc0;
	__BITS8 BIT;
};
union un_tkbtrg0 {
	unsigned char tkbtrg0;
	__BITS8 BIT;
};
union un_tkbflg0 {
	unsigned char tkbflg0;
	__BITS8 BIT;
};
union un_tkbioc00 {
	unsigned char tkbioc00;
	__BITS8 BIT;
};
union un_tkbclr0 {
	unsigned char tkbclr0;
	__BITS8 BIT;
};
union un_tkbioc01 {
	unsigned char tkbioc01;
	__BITS8 BIT;
};
union un_tkbctl01 {
	unsigned char tkbctl01;
	__BITS8 BIT;
};
union un_tkbpahfs0 {
	unsigned char tkbpahfs0;
	__BITS8 BIT;
};
union un_tkbpahft0 {
	unsigned char tkbpahft0;
	__BITS8 BIT;
};
union un_tkbpaflg0 {
	unsigned char tkbpaflg0;
	__BITS8 BIT;
};
union un_tkbpactl02 {
	unsigned char tkbpactl02;
	__BITS8 BIT;
};
union un_tkbtrg1 {
	unsigned char tkbtrg1;
	__BITS8 BIT;
};
union un_tkbflg1 {
	unsigned char tkbflg1;
	__BITS8 BIT;
};
union un_tkbioc10 {
	unsigned char tkbioc10;
	__BITS8 BIT;
};
union un_tkbclr1 {
	unsigned char tkbclr1;
	__BITS8 BIT;
};
union un_tkbioc11 {
	unsigned char tkbioc11;
	__BITS8 BIT;
};
union un_tkbctl11 {
	unsigned char tkbctl11;
	__BITS8 BIT;
};
union un_tkbpahfs1 {
	unsigned char tkbpahfs1;
	__BITS8 BIT;
};
union un_tkbpahft1 {
	unsigned char tkbpahft1;
	__BITS8 BIT;
};
union un_tkbpaflg1 {
	unsigned char tkbpaflg1;
	__BITS8 BIT;
};
union un_tkbpactl12 {
	unsigned char tkbpactl12;
	__BITS8 BIT;
};
union un_tkbtrg2 {
	unsigned char tkbtrg2;
	__BITS8 BIT;
};
union un_tkbflg2 {
	unsigned char tkbflg2;
	__BITS8 BIT;
};
union un_tkbioc20 {
	unsigned char tkbioc20;
	__BITS8 BIT;
};
union un_tkbclr2 {
	unsigned char tkbclr2;
	__BITS8 BIT;
};
union un_tkbioc21 {
	unsigned char tkbioc21;
	__BITS8 BIT;
};
union un_tkbctl21 {
	unsigned char tkbctl21;
	__BITS8 BIT;
};
union un_tkbpahfs2 {
	unsigned char tkbpahfs2;
	__BITS8 BIT;
};
union un_tkbpahft2 {
	unsigned char tkbpahft2;
	__BITS8 BIT;
};
union un_tkbpaflg2 {
	unsigned char tkbpaflg2;
	__BITS8 BIT;
};
union un_tkbpactl22 {
	unsigned char tkbpactl22;
	__BITS8 BIT;
};
union un_tkctrg0 {
	unsigned char tkctrg0;
	__BITS8 BIT;
};
union un_tkcflg0 {
	unsigned char tkcflg0;
	__BITS8 BIT;
};
union un_tkcioc01 {
	unsigned char tkcioc01;
	__BITS8 BIT;
};
union un_tkcctl0 {
	unsigned char tkcctl0;
	__BITS8 BIT;
};
union un_tkctof0 {
	unsigned char tkctof0;
	__BITS8 BIT;
};

#define ADM2 (*(volatile union un_adm2 *)0xF0010).adm2
#define ADM2_bit (*(volatile union un_adm2 *)0xF0010).BIT
#define ADUL (*(volatile unsigned char *)0xF0011)
#define ADLL (*(volatile unsigned char *)0xF0012)
#define ADTES (*(volatile unsigned char *)0xF0013)
#define PU0 (*(volatile union un_pu0 *)0xF0030).pu0
#define PU0_bit (*(volatile union un_pu0 *)0xF0030).BIT
#define PU1 (*(volatile union un_pu1 *)0xF0031).pu1
#define PU1_bit (*(volatile union un_pu1 *)0xF0031).BIT
#define PU3 (*(volatile union un_pu3 *)0xF0033).pu3
#define PU3_bit (*(volatile union un_pu3 *)0xF0033).BIT
#define PU4 (*(volatile union un_pu4 *)0xF0034).pu4
#define PU4_bit (*(volatile union un_pu4 *)0xF0034).BIT
#define PU7 (*(volatile union un_pu7 *)0xF0037).pu7
#define PU7_bit (*(volatile union un_pu7 *)0xF0037).BIT
#define PU12 (*(volatile union un_pu12 *)0xF003C).pu12
#define PU12_bit (*(volatile union un_pu12 *)0xF003C).BIT
#define PU14 (*(volatile union un_pu14 *)0xF003E).pu14
#define PU14_bit (*(volatile union un_pu14 *)0xF003E).BIT
#define PIM0 (*(volatile union un_pim0 *)0xF0040).pim0
#define PIM0_bit (*(volatile union un_pim0 *)0xF0040).BIT
#define PIM1 (*(volatile union un_pim1 *)0xF0041).pim1
#define PIM1_bit (*(volatile union un_pim1 *)0xF0041).BIT
#define POM0 (*(volatile union un_pom0 *)0xF0050).pom0
#define POM0_bit (*(volatile union un_pom0 *)0xF0050).BIT
#define POM1 (*(volatile union un_pom1 *)0xF0051).pom1
#define POM1_bit (*(volatile union un_pom1 *)0xF0051).BIT
#define PMC0 (*(volatile union un_pmc0 *)0xF0060).pmc0
#define PMC0_bit (*(volatile union un_pmc0 *)0xF0060).BIT
#define PMC12 (*(volatile union un_pmc12 *)0xF006C).pmc12
#define PMC12_bit (*(volatile union un_pmc12 *)0xF006C).BIT
#define PMC14 (*(volatile union un_pmc14 *)0xF006E).pmc14
#define PMC14_bit (*(volatile union un_pmc14 *)0xF006E).BIT
#define NFEN0 (*(volatile union un_nfen0 *)0xF0070).nfen0
#define NFEN0_bit (*(volatile union un_nfen0 *)0xF0070).BIT
#define NFEN1 (*(volatile union un_nfen1 *)0xF0071).nfen1
#define NFEN1_bit (*(volatile union un_nfen1 *)0xF0071).BIT
#define ISC (*(volatile union un_isc *)0xF0073).isc
#define ISC_bit (*(volatile union un_isc *)0xF0073).BIT
#define TIS0 (*(volatile unsigned char *)0xF0074)
#define ADPC (*(volatile unsigned char *)0xF0076)
#define IAWCTL0 (*(volatile unsigned char *)0xF0078)
#define DFLCTL (*(volatile union un_dflctl *)0xF0090).dflctl
#define DFLCTL_bit (*(volatile union un_dflctl *)0xF0090).BIT
#define HIOTRM (*(volatile unsigned char *)0xF00A0)
#define HOCODIV (*(volatile unsigned char *)0xF00A8)
#define TEMPCAL0 (*(volatile unsigned char *)0xF00AC)
#define TEMPCAL1 (*(volatile unsigned char *)0xF00AD)
#define TEMPCAL2 (*(volatile unsigned char *)0xF00AE)
#define TEMPCAL3 (*(volatile unsigned char *)0xF00AF)
#define MDCL (*(volatile unsigned short *)0xF00E0)
#define MDCH (*(volatile unsigned short *)0xF00E2)
#define MDUC (*(volatile union un_mduc *)0xF00E8).mduc
#define MDUC_bit (*(volatile union un_mduc *)0xF00E8).BIT
#define PER0 (*(volatile union un_per0 *)0xF00F0).per0
#define PER0_bit (*(volatile union un_per0 *)0xF00F0).BIT
#define OSMC (*(volatile unsigned char *)0xF00F3)
#define RMC (*(volatile union un_rmc *)0xF00F4).rmc
#define RMC_bit (*(volatile union un_rmc *)0xF00F4).BIT
#define RPECTL (*(volatile union un_rpectl *)0xF00F5).rpectl
#define RPECTL_bit (*(volatile union un_rpectl *)0xF00F5).BIT
#define BCDADJ (*(volatile unsigned char *)0xF00FE)
#define SSR00 (*(volatile unsigned short *)0xF0100)
#define SSR00L (*(volatile unsigned char *)0xF0100)
#define SSR01 (*(volatile unsigned short *)0xF0102)
#define SSR01L (*(volatile unsigned char *)0xF0102)
#define SSR02 (*(volatile unsigned short *)0xF0104)
#define SSR02L (*(volatile unsigned char *)0xF0104)
#define SSR03 (*(volatile unsigned short *)0xF0106)
#define SSR03L (*(volatile unsigned char *)0xF0106)
#define SIR00 (*(volatile unsigned short *)0xF0108)
#define SIR00L (*(volatile unsigned char *)0xF0108)
#define SIR01 (*(volatile unsigned short *)0xF010A)
#define SIR01L (*(volatile unsigned char *)0xF010A)
#define SIR02 (*(volatile unsigned short *)0xF010C)
#define SIR02L (*(volatile unsigned char *)0xF010C)
#define SIR03 (*(volatile unsigned short *)0xF010E)
#define SIR03L (*(volatile unsigned char *)0xF010E)
#define SMR00 (*(volatile unsigned short *)0xF0110)
#define SMR01 (*(volatile unsigned short *)0xF0112)
#define SMR02 (*(volatile unsigned short *)0xF0114)
#define SMR03 (*(volatile unsigned short *)0xF0116)
#define SCR00 (*(volatile unsigned short *)0xF0118)
#define SCR01 (*(volatile unsigned short *)0xF011A)
#define SCR02 (*(volatile unsigned short *)0xF011C)
#define SCR03 (*(volatile unsigned short *)0xF011E)
#define SE0 (*(volatile unsigned short *)0xF0120)
#define SE0L (*(volatile union un_se0l *)0xF0120).se0l
#define SE0L_bit (*(volatile union un_se0l *)0xF0120).BIT
#define SS0 (*(volatile unsigned short *)0xF0122)
#define SS0L (*(volatile union un_ss0l *)0xF0122).ss0l
#define SS0L_bit (*(volatile union un_ss0l *)0xF0122).BIT
#define ST0 (*(volatile unsigned short *)0xF0124)
#define ST0L (*(volatile union un_st0l *)0xF0124).st0l
#define ST0L_bit (*(volatile union un_st0l *)0xF0124).BIT
#define SPS0 (*(volatile unsigned short *)0xF0126)
#define SPS0L (*(volatile unsigned char *)0xF0126)
#define SO0 (*(volatile unsigned short *)0xF0128)
#define SOE0 (*(volatile unsigned short *)0xF012A)
#define SOE0L (*(volatile union un_soe0l *)0xF012A).soe0l
#define SOE0L_bit (*(volatile union un_soe0l *)0xF012A).BIT
#define SOL0 (*(volatile unsigned short *)0xF0134)
#define SOL0L (*(volatile unsigned char *)0xF0134)
#define SSC0 (*(volatile unsigned short *)0xF0138)
#define SSC0L (*(volatile unsigned char *)0xF0138)
#define TCR00 (*(volatile unsigned short *)0xF0180)
#define TCR01 (*(volatile unsigned short *)0xF0182)
#define TCR02 (*(volatile unsigned short *)0xF0184)
#define TCR03 (*(volatile unsigned short *)0xF0186)
#define TCR04 (*(volatile unsigned short *)0xF0188)
#define TCR05 (*(volatile unsigned short *)0xF018A)
#define TCR06 (*(volatile unsigned short *)0xF018C)
#define TCR07 (*(volatile unsigned short *)0xF018E)
#define TMR00 (*(volatile unsigned short *)0xF0190)
#define TMR01 (*(volatile unsigned short *)0xF0192)
#define TMR02 (*(volatile unsigned short *)0xF0194)
#define TMR03 (*(volatile unsigned short *)0xF0196)
#define TMR04 (*(volatile unsigned short *)0xF0198)
#define TMR05 (*(volatile unsigned short *)0xF019A)
#define TMR06 (*(volatile unsigned short *)0xF019C)
#define TMR07 (*(volatile unsigned short *)0xF019E)
#define TSR00 (*(volatile unsigned short *)0xF01A0)
#define TSR00L (*(volatile unsigned char *)0xF01A0)
#define TSR01 (*(volatile unsigned short *)0xF01A2)
#define TSR01L (*(volatile unsigned char *)0xF01A2)
#define TSR02 (*(volatile unsigned short *)0xF01A4)
#define TSR02L (*(volatile unsigned char *)0xF01A4)
#define TSR03 (*(volatile unsigned short *)0xF01A6)
#define TSR03L (*(volatile unsigned char *)0xF01A6)
#define TSR04 (*(volatile unsigned short *)0xF01A8)
#define TSR04L (*(volatile unsigned char *)0xF01A8)
#define TSR05 (*(volatile unsigned short *)0xF01AA)
#define TSR05L (*(volatile unsigned char *)0xF01AA)
#define TSR06 (*(volatile unsigned short *)0xF01AC)
#define TSR06L (*(volatile unsigned char *)0xF01AC)
#define TSR07 (*(volatile unsigned short *)0xF01AE)
#define TSR07L (*(volatile unsigned char *)0xF01AE)
#define TE0 (*(volatile unsigned short *)0xF01B0)
#define TE0L (*(volatile union un_te0l *)0xF01B0).te0l
#define TE0L_bit (*(volatile union un_te0l *)0xF01B0).BIT
#define TS0 (*(volatile unsigned short *)0xF01B2)
#define TS0L (*(volatile union un_ts0l *)0xF01B2).ts0l
#define TS0L_bit (*(volatile union un_ts0l *)0xF01B2).BIT
#define TT0 (*(volatile unsigned short *)0xF01B4)
#define TT0L (*(volatile union un_tt0l *)0xF01B4).tt0l
#define TT0L_bit (*(volatile union un_tt0l *)0xF01B4).BIT
#define TPS0 (*(volatile unsigned short *)0xF01B6)
#define TO0 (*(volatile unsigned short *)0xF01B8)
#define TO0L (*(volatile unsigned char *)0xF01B8)
#define TOE0 (*(volatile unsigned short *)0xF01BA)
#define TOE0L (*(volatile union un_toe0l *)0xF01BA).toe0l
#define TOE0L_bit (*(volatile union un_toe0l *)0xF01BA).BIT
#define TOL0 (*(volatile unsigned short *)0xF01BC)
#define TOL0L (*(volatile unsigned char *)0xF01BC)
#define TOM0 (*(volatile unsigned short *)0xF01BE)
#define TOM0L (*(volatile unsigned char *)0xF01BE)
#define IICCTL00 (*(volatile union un_iicctl00 *)0xF0230).iicctl00
#define IICCTL00_bit (*(volatile union un_iicctl00 *)0xF0230).BIT
#define IICCTL01 (*(volatile union un_iicctl01 *)0xF0231).iicctl01
#define IICCTL01_bit (*(volatile union un_iicctl01 *)0xF0231).BIT
#define IICWL0 (*(volatile unsigned char *)0xF0232)
#define IICWH0 (*(volatile unsigned char *)0xF0233)
#define SVA0 (*(volatile unsigned char *)0xF0234)
#define CRC0CTL (*(volatile union un_crc0ctl *)0xF02F0).crc0ctl
#define CRC0CTL_bit (*(volatile union un_crc0ctl *)0xF02F0).BIT
#define PGCRCL (*(volatile unsigned short *)0xF02F2)
#define CRCD (*(volatile unsigned short *)0xF02FA)
#define P20 (*(volatile union un_p20 *)0xF0500).p20
#define P20_bit (*(volatile union un_p20 *)0xF0500).BIT
#define PER1 (*(volatile union un_per1 *)0xF0508).per1
#define PER1_bit (*(volatile union un_per1 *)0xF0508).BIT
#define PER2 (*(volatile union un_per2 *)0xF0509).per2
#define PER2_bit (*(volatile union un_per2 *)0xF0509).BIT
#define PLLCTL (*(volatile union un_pllctl *)0xF050A).pllctl
#define PLLCTL_bit (*(volatile union un_pllctl *)0xF050A).BIT
#define PM20 (*(volatile union un_pm20 *)0xF0510).pm20
#define PM20_bit (*(volatile union un_pm20 *)0xF0510).BIT
#define EGP2 (*(volatile union un_egp2 *)0xF0518).egp2
#define EGP2_bit (*(volatile union un_egp2 *)0xF0518).BIT
#define EGN2 (*(volatile union un_egn2 *)0xF0519).egn2
#define EGN2_bit (*(volatile union un_egn2 *)0xF0519).BIT
#define PU20 (*(volatile union un_pu20 *)0xF0520).pu20
#define PU20_bit (*(volatile union un_pu20 *)0xF0520).BIT
#define POM20 (*(volatile union un_pom20 *)0xF0530).pom20
#define POM20_bit (*(volatile union un_pom20 *)0xF0530).BIT
#define PGACTL (*(volatile union un_pgactl *)0xF0550).pgactl
#define PGACTL_bit (*(volatile union un_pgactl *)0xF0550).BIT
#define PGAINS (*(volatile unsigned char *)0xF0551)
#define C0CTL (*(volatile union un_c0ctl *)0xF0552).c0ctl
#define C0CTL_bit (*(volatile union un_c0ctl *)0xF0552).BIT
#define C1CTL (*(volatile union un_c1ctl *)0xF0553).c1ctl
#define C1CTL_bit (*(volatile union un_c1ctl *)0xF0553).BIT
#define C2CTL (*(volatile union un_c2ctl *)0xF0554).c2ctl
#define C2CTL_bit (*(volatile union un_c2ctl *)0xF0554).BIT
#define C3CTL (*(volatile union un_c3ctl *)0xF0555).c3ctl
#define C3CTL_bit (*(volatile union un_c3ctl *)0xF0555).BIT
#define C4CTL (*(volatile union un_c4ctl *)0xF0556).c4ctl
#define C4CTL_bit (*(volatile union un_c4ctl *)0xF0556).BIT
#define C5CTL (*(volatile union un_c5ctl *)0xF0557).c5ctl
#define C5CTL_bit (*(volatile union un_c5ctl *)0xF0557).BIT
#define CMPEGP0 (*(volatile union un_cmpegp0 *)0xF0558).cmpegp0
#define CMPEGP0_bit (*(volatile union un_cmpegp0 *)0xF0558).BIT
#define CMPEGN0 (*(volatile union un_cmpegn0 *)0xF0559).cmpegn0
#define CMPEGN0_bit (*(volatile union un_cmpegn0 *)0xF0559).BIT
#define CMPMON (*(volatile union un_cmpmon *)0xF055A).cmpmon
#define CMPMON_bit (*(volatile union un_cmpmon *)0xF055A).BIT
#define INTPCTL (*(volatile union un_intpctl *)0xF055B).intpctl
#define INTPCTL_bit (*(volatile union un_intpctl *)0xF055B).BIT
#define CVRCTL (*(volatile union un_cvrctl *)0xF0560).cvrctl
#define CVRCTL_bit (*(volatile union un_cvrctl *)0xF0560).BIT
#define C0RVM (*(volatile unsigned char *)0xF0561)
#define C1RVM (*(volatile unsigned char *)0xF0562)
#define C2RVM (*(volatile unsigned char *)0xF0563)
#define CMPWDC (*(volatile union un_cmpwdc *)0xF0564).cmpwdc
#define CMPWDC_bit (*(volatile union un_cmpwdc *)0xF0564).BIT
#define SDR40 (*(volatile unsigned short *)0xF0570)
#define TXD4 (*(volatile unsigned char *)0xF0570)
#define SDR41 (*(volatile unsigned short *)0xF0572)
#define RXD4 (*(volatile unsigned char *)0xF0572)
#define SDTL4 (*(volatile unsigned short *)0xF0578)
#define SDTH4 (*(volatile unsigned short *)0xF057A)
#define SDCL4 (*(volatile unsigned short *)0xF057C)
#define SDCH4 (*(volatile unsigned short *)0xF057E)
#define SSR40 (*(volatile unsigned short *)0xF0580)
#define SSR40L (*(volatile unsigned char *)0xF0580)
#define SSR41 (*(volatile unsigned short *)0xF0582)
#define SSR41L (*(volatile unsigned char *)0xF0582)
#define SIR40 (*(volatile unsigned short *)0xF0588)
#define SIR40L (*(volatile unsigned char *)0xF0588)
#define SIR41 (*(volatile unsigned short *)0xF058A)
#define SIR41L (*(volatile unsigned char *)0xF058A)
#define SMR40 (*(volatile unsigned short *)0xF0590)
#define SMR41 (*(volatile unsigned short *)0xF0592)
#define SCR40 (*(volatile unsigned short *)0xF0598)
#define SCR41 (*(volatile unsigned short *)0xF059A)
#define SE4 (*(volatile unsigned short *)0xF05A0)
#define SE4L (*(volatile union un_se4l *)0xF05A0).se4l
#define SE4L_bit (*(volatile union un_se4l *)0xF05A0).BIT
#define SS4 (*(volatile unsigned short *)0xF05A2)
#define SS4L (*(volatile union un_ss4l *)0xF05A2).ss4l
#define SS4L_bit (*(volatile union un_ss4l *)0xF05A2).BIT
#define ST4 (*(volatile unsigned short *)0xF05A4)
#define ST4L (*(volatile union un_st4l *)0xF05A4).st4l
#define ST4L_bit (*(volatile union un_st4l *)0xF05A4).BIT
#define SPS4 (*(volatile unsigned short *)0xF05A6)
#define SPS4L (*(volatile unsigned char *)0xF05A6)
#define SO4 (*(volatile unsigned short *)0xF05A8)
#define SOE4 (*(volatile unsigned short *)0xF05AA)
#define SOE4L (*(volatile union un_soe4l *)0xF05AA).soe4l
#define SOE4L_bit (*(volatile union un_soe4l *)0xF05AA).BIT
#define SOL4 (*(volatile unsigned short *)0xF05B4)
#define SOL4L (*(volatile unsigned char *)0xF05B4)
#define SSC4 (*(volatile unsigned short *)0xF05B8)
#define SSC4L (*(volatile unsigned char *)0xF05B8)
#define SOC4 (*(volatile unsigned short *)0xF05BA)
#define PIOR1 (*(volatile unsigned char *)0xF05C0)
#define NFEN3 (*(volatile union un_nfen3 *)0xF05C1).nfen3
#define NFEN3_bit (*(volatile union un_nfen3 *)0xF05C1).BIT
#define INTMK0 (*(volatile union un_intmk0 *)0xF05C2).intmk0
#define INTMK0_bit (*(volatile union un_intmk0 *)0xF05C2).BIT
#define INTMF0 (*(volatile union un_intmf0 *)0xF05C3).intmf0
#define INTMF0_bit (*(volatile union un_intmf0 *)0xF05C3).BIT
#define IAWCTL1 (*(volatile unsigned char *)0xF05C4)
#define TPS2 (*(volatile unsigned char *)0xF05C5)
#define PFSEL0 (*(volatile union un_pfsel0 *)0xF05C6).pfsel0
#define PFSEL0_bit (*(volatile union un_pfsel0 *)0xF05C6).BIT
#define SUCTL (*(volatile union un_suctl *)0xF05C7).suctl
#define SUCTL_bit (*(volatile union un_suctl *)0xF05C7).BIT
#define TOETKC0 (*(volatile union un_toetkc0 *)0xF05C8).toetkc0
#define TOETKC0_bit (*(volatile union un_toetkc0 *)0xF05C8).BIT
#define TKBCR00 (*(volatile unsigned short *)0xF0600)
#define TKBCR01 (*(volatile unsigned short *)0xF0602)
#define TKBCR02 (*(volatile unsigned short *)0xF0604)
#define TKBCR03 (*(volatile unsigned short *)0xF0606)
#define TKBTGCR0 (*(volatile unsigned short *)0xF0608)
#define TKBSIR00 (*(volatile unsigned short *)0xF060A)
#define TKBSIR01 (*(volatile unsigned short *)0xF060C)
#define TKBDNR00 (*(volatile unsigned char *)0xF060E)
#define TKBSSR00 (*(volatile unsigned char *)0xF060F)
#define TKBDNR01 (*(volatile unsigned char *)0xF0610)
#define TKBSSR01 (*(volatile unsigned char *)0xF0611)
#define TKBTRG0 (*(volatile union un_tkbtrg0 *)0xF0612).tkbtrg0
#define TKBTRG0_bit (*(volatile union un_tkbtrg0 *)0xF0612).BIT
#define TKBFLG0 (*(volatile union un_tkbflg0 *)0xF0613).tkbflg0
#define TKBFLG0_bit (*(volatile union un_tkbflg0 *)0xF0613).BIT
#define TKBCRLD00 (*(volatile unsigned short *)0xF0614)
#define TKBCRLD01 (*(volatile unsigned short *)0xF0616)
#define TKBCNT0 (*(volatile unsigned short *)0xF0620)
#define TKBCTL00 (*(volatile unsigned short *)0xF0622)
#define TKBMFR0 (*(volatile unsigned short *)0xF0624)
#define TKBIOC00 (*(volatile union un_tkbioc00 *)0xF0626).tkbioc00
#define TKBIOC00_bit (*(volatile union un_tkbioc00 *)0xF0626).BIT
#define TKBCLR0 (*(volatile union un_tkbclr0 *)0xF0627).tkbclr0
#define TKBCLR0_bit (*(volatile union un_tkbclr0 *)0xF0627).BIT
#define TKBIOC01 (*(volatile union un_tkbioc01 *)0xF0628).tkbioc01
#define TKBIOC01_bit (*(volatile union un_tkbioc01 *)0xF0628).BIT
#define TKBCTL01 (*(volatile union un_tkbctl01 *)0xF0629).tkbctl01
#define TKBCTL01_bit (*(volatile union un_tkbctl01 *)0xF0629).BIT
#define TKBPACTL00 (*(volatile unsigned short *)0xF0630)
#define TKBPACTL01 (*(volatile unsigned short *)0xF0632)
#define TKBPAHFS0 (*(volatile union un_tkbpahfs0 *)0xF0634).tkbpahfs0
#define TKBPAHFS0_bit (*(volatile union un_tkbpahfs0 *)0xF0634).BIT
#define TKBPAHFT0 (*(volatile union un_tkbpahft0 *)0xF0635).tkbpahft0
#define TKBPAHFT0_bit (*(volatile union un_tkbpahft0 *)0xF0635).BIT
#define TKBPAFLG0 (*(volatile union un_tkbpaflg0 *)0xF0636).tkbpaflg0
#define TKBPAFLG0_bit (*(volatile union un_tkbpaflg0 *)0xF0636).BIT
#define TKBPACTL02 (*(volatile union un_tkbpactl02 *)0xF0637).tkbpactl02
#define TKBPACTL02_bit (*(volatile union un_tkbpactl02 *)0xF0637).BIT
#define TKBCR10 (*(volatile unsigned short *)0xF0640)
#define TKBCR11 (*(volatile unsigned short *)0xF0642)
#define TKBCR12 (*(volatile unsigned short *)0xF0644)
#define TKBCR13 (*(volatile unsigned short *)0xF0646)
#define TKBTGCR1 (*(volatile unsigned short *)0xF0648)
#define TKBSIR10 (*(volatile unsigned short *)0xF064A)
#define TKBSIR11 (*(volatile unsigned short *)0xF064C)
#define TKBDNR10 (*(volatile unsigned char *)0xF064E)
#define TKBSSR10 (*(volatile unsigned char *)0xF064F)
#define TKBDNR11 (*(volatile unsigned char *)0xF0650)
#define TKBSSR11 (*(volatile unsigned char *)0xF0651)
#define TKBTRG1 (*(volatile union un_tkbtrg1 *)0xF0652).tkbtrg1
#define TKBTRG1_bit (*(volatile union un_tkbtrg1 *)0xF0652).BIT
#define TKBFLG1 (*(volatile union un_tkbflg1 *)0xF0653).tkbflg1
#define TKBFLG1_bit (*(volatile union un_tkbflg1 *)0xF0653).BIT
#define TKBCRLD10 (*(volatile unsigned short *)0xF0654)
#define TKBCRLD11 (*(volatile unsigned short *)0xF0656)
#define TKBCNT1 (*(volatile unsigned short *)0xF0660)
#define TKBCTL10 (*(volatile unsigned short *)0xF0662)
#define TKBMFR1 (*(volatile unsigned short *)0xF0664)
#define TKBIOC10 (*(volatile union un_tkbioc10 *)0xF0666).tkbioc10
#define TKBIOC10_bit (*(volatile union un_tkbioc10 *)0xF0666).BIT
#define TKBCLR1 (*(volatile union un_tkbclr1 *)0xF0667).tkbclr1
#define TKBCLR1_bit (*(volatile union un_tkbclr1 *)0xF0667).BIT
#define TKBIOC11 (*(volatile union un_tkbioc11 *)0xF0668).tkbioc11
#define TKBIOC11_bit (*(volatile union un_tkbioc11 *)0xF0668).BIT
#define TKBCTL11 (*(volatile union un_tkbctl11 *)0xF0669).tkbctl11
#define TKBCTL11_bit (*(volatile union un_tkbctl11 *)0xF0669).BIT
#define TKBPACTL10 (*(volatile unsigned short *)0xF0670)
#define TKBPACTL11 (*(volatile unsigned short *)0xF0672)
#define TKBPAHFS1 (*(volatile union un_tkbpahfs1 *)0xF0674).tkbpahfs1
#define TKBPAHFS1_bit (*(volatile union un_tkbpahfs1 *)0xF0674).BIT
#define TKBPAHFT1 (*(volatile union un_tkbpahft1 *)0xF0675).tkbpahft1
#define TKBPAHFT1_bit (*(volatile union un_tkbpahft1 *)0xF0675).BIT
#define TKBPAFLG1 (*(volatile union un_tkbpaflg1 *)0xF0676).tkbpaflg1
#define TKBPAFLG1_bit (*(volatile union un_tkbpaflg1 *)0xF0676).BIT
#define TKBPACTL12 (*(volatile union un_tkbpactl12 *)0xF0677).tkbpactl12
#define TKBPACTL12_bit (*(volatile union un_tkbpactl12 *)0xF0677).BIT
#define TKBCR20 (*(volatile unsigned short *)0xF0680)
#define TKBCR21 (*(volatile unsigned short *)0xF0682)
#define TKBCR22 (*(volatile unsigned short *)0xF0684)
#define TKBCR23 (*(volatile unsigned short *)0xF0686)
#define TKBTGCR2 (*(volatile unsigned short *)0xF0688)
#define TKBSIR20 (*(volatile unsigned short *)0xF068A)
#define TKBSIR21 (*(volatile unsigned short *)0xF068C)
#define TKBDNR20 (*(volatile unsigned char *)0xF068E)
#define TKBSSR20 (*(volatile unsigned char *)0xF068F)
#define TKBDNR21 (*(volatile unsigned char *)0xF0690)
#define TKBSSR21 (*(volatile unsigned char *)0xF0691)
#define TKBTRG2 (*(volatile union un_tkbtrg2 *)0xF0692).tkbtrg2
#define TKBTRG2_bit (*(volatile union un_tkbtrg2 *)0xF0692).BIT
#define TKBFLG2 (*(volatile union un_tkbflg2 *)0xF0693).tkbflg2
#define TKBFLG2_bit (*(volatile union un_tkbflg2 *)0xF0693).BIT
#define TKBCRLD20 (*(volatile unsigned short *)0xF0694)
#define TKBCRLD21 (*(volatile unsigned short *)0xF0696)
#define TKBCNT2 (*(volatile unsigned short *)0xF06A0)
#define TKBCTL20 (*(volatile unsigned short *)0xF06A2)
#define TKBMFR2 (*(volatile unsigned short *)0xF06A4)
#define TKBIOC20 (*(volatile union un_tkbioc20 *)0xF06A6).tkbioc20
#define TKBIOC20_bit (*(volatile union un_tkbioc20 *)0xF06A6).BIT
#define TKBCLR2 (*(volatile union un_tkbclr2 *)0xF06A7).tkbclr2
#define TKBCLR2_bit (*(volatile union un_tkbclr2 *)0xF06A7).BIT
#define TKBIOC21 (*(volatile union un_tkbioc21 *)0xF06A8).tkbioc21
#define TKBIOC21_bit (*(volatile union un_tkbioc21 *)0xF06A8).BIT
#define TKBCTL21 (*(volatile union un_tkbctl21 *)0xF06A9).tkbctl21
#define TKBCTL21_bit (*(volatile union un_tkbctl21 *)0xF06A9).BIT
#define TKBPACTL20 (*(volatile unsigned short *)0xF06B0)
#define TKBPACTL21 (*(volatile unsigned short *)0xF06B2)
#define TKBPAHFS2 (*(volatile union un_tkbpahfs2 *)0xF06B4).tkbpahfs2
#define TKBPAHFS2_bit (*(volatile union un_tkbpahfs2 *)0xF06B4).BIT
#define TKBPAHFT2 (*(volatile union un_tkbpahft2 *)0xF06B5).tkbpahft2
#define TKBPAHFT2_bit (*(volatile union un_tkbpahft2 *)0xF06B5).BIT
#define TKBPAFLG2 (*(volatile union un_tkbpaflg2 *)0xF06B6).tkbpaflg2
#define TKBPAFLG2_bit (*(volatile union un_tkbpaflg2 *)0xF06B6).BIT
#define TKBPACTL22 (*(volatile union un_tkbpactl22 *)0xF06B7).tkbpactl22
#define TKBPACTL22_bit (*(volatile union un_tkbpactl22 *)0xF06B7).BIT
#define TKCCR0 (*(volatile unsigned short *)0xF06D0)
#define TKCDUTY00 (*(volatile unsigned short *)0xF06D2)
#define TKCDUTY01 (*(volatile unsigned short *)0xF06D4)
#define TKCDUTY02 (*(volatile unsigned short *)0xF06D6)
#define TKCDUTY03 (*(volatile unsigned short *)0xF06D8)
#define TKCDUTY04 (*(volatile unsigned short *)0xF06DA)
#define TKCDUTY05 (*(volatile unsigned short *)0xF06DC)
#define TKCTRG0 (*(volatile union un_tkctrg0 *)0xF06DE).tkctrg0
#define TKCTRG0_bit (*(volatile union un_tkctrg0 *)0xF06DE).BIT
#define TKCFLG0 (*(volatile union un_tkcflg0 *)0xF06DF).tkcflg0
#define TKCFLG0_bit (*(volatile union un_tkcflg0 *)0xF06DF).BIT
#define TKCCNT0 (*(volatile unsigned short *)0xF06E0)
#define TKCIOC00 (*(volatile unsigned short *)0xF06E2)
#define TKCIOC01 (*(volatile union un_tkcioc01 *)0xF06E4).tkcioc01
#define TKCIOC01_bit (*(volatile union un_tkcioc01 *)0xF06E4).BIT
#define TKCCTL0 (*(volatile union un_tkcctl0 *)0xF06E5).tkcctl0
#define TKCCTL0_bit (*(volatile union un_tkcctl0 *)0xF06E5).BIT
#define TKCTOF0 (*(volatile union un_tkctof0 *)0xF06E6).tkctof0
#define TKCTOF0_bit (*(volatile union un_tkctof0 *)0xF06E6).BIT

/*
 Sfr bits
 */
#define ADTYP ADM2_bit.no0
#define AWC ADM2_bit.no2
#define ADRCK ADM2_bit.no3
#define DFLEN DFLCTL_bit.no0
#define DIVST MDUC_bit.no0
#define MACSF MDUC_bit.no1
#define MACOF MDUC_bit.no2
#define MDSM MDUC_bit.no3
#define MACMODE MDUC_bit.no6
#define DIVMODE MDUC_bit.no7
#define TAU0EN PER0_bit.no0
#define SAU0EN PER0_bit.no2
#define IICA0EN PER0_bit.no4
#define ADCEN PER0_bit.no5
#define RTCEN PER0_bit.no7
#define WDVOL RMC_bit.no7
#define RPEF RPECTL_bit.no0
#define RPERDIS RPECTL_bit.no7
#define SPT0 IICCTL00_bit.no0
#define STT0 IICCTL00_bit.no1
#define ACKE0 IICCTL00_bit.no2
#define WTIM0 IICCTL00_bit.no3
#define SPIE0 IICCTL00_bit.no4
#define WREL0 IICCTL00_bit.no5
#define LREL0 IICCTL00_bit.no6
#define IICE0 IICCTL00_bit.no7
#define PRS0 IICCTL01_bit.no0
#define DFC0 IICCTL01_bit.no2
#define SMC0 IICCTL01_bit.no3
#define DAD0 IICCTL01_bit.no4
#define CLD0 IICCTL01_bit.no5
#define WUP0 IICCTL01_bit.no7
#define CRC0EN CRC0CTL_bit.no7
#define DALIEN PER1_bit.no0
#define TKB0EN PER2_bit.no0
#define TKB1EN PER2_bit.no1
#define TKB2EN PER2_bit.no2
#define TKC0EN PER2_bit.no3
#define TKBPA0EN PER2_bit.no4
#define TKBPA1EN PER2_bit.no5
#define TKBPA2EN PER2_bit.no6
#define PGACMPEN PER2_bit.no7
#define PLLON PLLCTL_bit.no0
#define PLLO PLLCTL_bit.no1
#define SELPLL PLLCTL_bit.no2
#define PLLS PLLCTL_bit.no3
#define PGAEN PGACTL_bit.no7
#define C0OE C0CTL_bit.no1
#define CMP0EN C0CTL_bit.no7
#define C1OE C1CTL_bit.no1
#define CMP1EN C1CTL_bit.no7
#define C2OE C2CTL_bit.no1
#define CMP2EN C2CTL_bit.no7
#define C3OE C3CTL_bit.no1
#define CMP3EN C3CTL_bit.no7
#define C4OE C4CTL_bit.no1
#define CMP4EN C4CTL_bit.no7
#define C5OE C5CTL_bit.no1
#define CMP5EN C5CTL_bit.no7
#define CMPMON0 CMPMON_bit.no0
#define CMPMON1 CMPMON_bit.no1
#define CMPMON2 CMPMON_bit.no2
#define CMPMON3 CMPMON_bit.no3
#define CMPMON4 CMPMON_bit.no4
#define CMPMON5 CMPMON_bit.no5
#define INTPINV0 INTPCTL_bit.no0
#define INTPINV1 INTPCTL_bit.no1
#define CVRE0 CVRCTL_bit.no0
#define CVRE1 CVRCTL_bit.no1
#define CVRE2 CVRCTL_bit.no2
#define WCSEL0 CMPWDC_bit.no0
#define WCSEL1 CMPWDC_bit.no1
#define WCSEL2 CMPWDC_bit.no2
#define INTMK00 INTMK0_bit.no0
#define INTMK01 INTMK0_bit.no1
#define INTMK02 INTMK0_bit.no2
#define INTMK03 INTMK0_bit.no3
#define INTMK04 INTMK0_bit.no4
#define INTMK05 INTMK0_bit.no5
#define INTMK06 INTMK0_bit.no6
#define INTMF00 INTMF0_bit.no0
#define INTMF01 INTMF0_bit.no1
#define INTMF02 INTMF0_bit.no2
#define INTMF03 INTMF0_bit.no3
#define TMRSTEN0 PFSEL0_bit.no0
#define TMRSTEN1 PFSEL0_bit.no1
#define PNFEN PFSEL0_bit.no4
#define CMP0STEN PFSEL0_bit.no5
#define CMP2STEN PFSEL0_bit.no6
#define TOETKC00 TOETKC0_bit.no0
#define TOETKC01 TOETKC0_bit.no1
#define TOETKC02 TOETKC0_bit.no2
#define TOETKC03 TOETKC0_bit.no3
#define TOETKC04 TOETKC0_bit.no4
#define TOETKC05 TOETKC0_bit.no5
#define TKBRDT0 TKBTRG0_bit.no0
#define TKBRSF0 TKBFLG0_bit.no0
#define TKBMFF0 TKBFLG0_bit.no1
#define TKBIEF0 TKBFLG0_bit.no2
#define TKBIRF0 TKBFLG0_bit.no3
#define TKBSEF00 TKBFLG0_bit.no4
#define TKBSEF01 TKBFLG0_bit.no5
#define TKBSSF00 TKBFLG0_bit.no6
#define TKBSSF01 TKBFLG0_bit.no7
#define TKBTOD00 TKBIOC00_bit.no0
#define TKBTOD01 TKBIOC00_bit.no1
#define TKBTOL00 TKBIOC00_bit.no2
#define TKBTOL01 TKBIOC00_bit.no3
#define TKBCLMF0 TKBCLR0_bit.no1
#define TKBCLIE0 TKBCLR0_bit.no2
#define TKBCLIR0 TKBCLR0_bit.no3
#define TKBCLSE00 TKBCLR0_bit.no4
#define TKBCLSE01 TKBCLR0_bit.no5
#define TKBTOE00 TKBIOC01_bit.no0
#define TKBTOE01 TKBIOC01_bit.no1
#define TKBCE0 TKBCTL01_bit.no7
#define TKBPAHTS00 TKBPAHFS0_bit.no0
#define TKBPAHTS01 TKBPAHFS0_bit.no1
#define TKBPAHTT00 TKBPAHFT0_bit.no0
#define TKBPAHTT01 TKBPAHFT0_bit.no1
#define TKBPAHIF00 TKBPAFLG0_bit.no0
#define TKBPAFIF00 TKBPAFLG0_bit.no1
#define TKBPAHIF01 TKBPAFLG0_bit.no2
#define TKBPAFIF01 TKBPAFLG0_bit.no3
#define TKBPAHSF00 TKBPAFLG0_bit.no4
#define TKBPAFSF00 TKBPAFLG0_bit.no5
#define TKBPAHSF01 TKBPAFLG0_bit.no6
#define TKBPAFSF01 TKBPAFLG0_bit.no7
#define TKBPACE00 TKBPACTL02_bit.no0
#define TKBPACE01 TKBPACTL02_bit.no1
#define TKBRDT1 TKBTRG1_bit.no0
#define TKBRSF1 TKBFLG1_bit.no0
#define TKBMFF1 TKBFLG1_bit.no1
#define TKBIEF1 TKBFLG1_bit.no2
#define TKBIRF1 TKBFLG1_bit.no3
#define TKBSEF10 TKBFLG1_bit.no4
#define TKBSEF11 TKBFLG1_bit.no5
#define TKBSSF10 TKBFLG1_bit.no6
#define TKBSSF11 TKBFLG1_bit.no7
#define TKBTOD10 TKBIOC10_bit.no0
#define TKBTOD11 TKBIOC10_bit.no1
#define TKBTOL10 TKBIOC10_bit.no2
#define TKBTOL11 TKBIOC10_bit.no3
#define TKBCLMF1 TKBCLR1_bit.no1
#define TKBCLIE1 TKBCLR1_bit.no2
#define TKBCLIR1 TKBCLR1_bit.no3
#define TKBCLSE10 TKBCLR1_bit.no4
#define TKBCLSE11 TKBCLR1_bit.no5
#define TKBTOE10 TKBIOC11_bit.no0
#define TKBTOE11 TKBIOC11_bit.no1
#define TKBCE1 TKBCTL11_bit.no7
#define TKBPAHTS10 TKBPAHFS1_bit.no0
#define TKBPAHTS11 TKBPAHFS1_bit.no1
#define TKBPAHTT10 TKBPAHFT1_bit.no0
#define TKBPAHTT11 TKBPAHFT1_bit.no1
#define TKBPAHIF10 TKBPAFLG1_bit.no0
#define TKBPAFIF10 TKBPAFLG1_bit.no1
#define TKBPAHIF11 TKBPAFLG1_bit.no2
#define TKBPAFIF11 TKBPAFLG1_bit.no3
#define TKBPAHSF10 TKBPAFLG1_bit.no4
#define TKBPAFSF10 TKBPAFLG1_bit.no5
#define TKBPAHSF11 TKBPAFLG1_bit.no6
#define TKBPAFSF11 TKBPAFLG1_bit.no7
#define TKBPACE10 TKBPACTL12_bit.no0
#define TKBPACE11 TKBPACTL12_bit.no1
#define TKBRDT2 TKBTRG2_bit.no0
#define TKBRSF2 TKBFLG2_bit.no0
#define TKBMFF2 TKBFLG2_bit.no1
#define TKBIEF2 TKBFLG2_bit.no2
#define TKBIRF2 TKBFLG2_bit.no3
#define TKBSEF20 TKBFLG2_bit.no4
#define TKBSEF21 TKBFLG2_bit.no5
#define TKBSSF20 TKBFLG2_bit.no6
#define TKBSSF21 TKBFLG2_bit.no7
#define TKBTOD20 TKBIOC20_bit.no0
#define TKBTOD21 TKBIOC20_bit.no1
#define TKBTOL20 TKBIOC20_bit.no2
#define TKBTOL21 TKBIOC20_bit.no3
#define TKBCLMF2 TKBCLR2_bit.no1
#define TKBCLIE2 TKBCLR2_bit.no2
#define TKBCLIR2 TKBCLR2_bit.no3
#define TKBCLSE20 TKBCLR2_bit.no4
#define TKBCLSE21 TKBCLR2_bit.no5
#define TKBTOE20 TKBIOC21_bit.no0
#define TKBTOE21 TKBIOC21_bit.no1
#define TKBCE2 TKBCTL21_bit.no7
#define TKBPAHTS20 TKBPAHFS2_bit.no0
#define TKBPAHTS21 TKBPAHFS2_bit.no1
#define TKBPAHTT20 TKBPAHFT2_bit.no0
#define TKBPAHTT21 TKBPAHFT2_bit.no1
#define TKBPAHIF20 TKBPAFLG2_bit.no0
#define TKBPAFIF20 TKBPAFLG2_bit.no1
#define TKBPAHIF21 TKBPAFLG2_bit.no2
#define TKBPAFIF21 TKBPAFLG2_bit.no3
#define TKBPAHSF20 TKBPAFLG2_bit.no4
#define TKBPAFSF20 TKBPAFLG2_bit.no5
#define TKBPAHSF21 TKBPAFLG2_bit.no6
#define TKBPAFSF21 TKBPAFLG2_bit.no7
#define TKBPACE20 TKBPACTL22_bit.no0
#define TKBPACE21 TKBPACTL22_bit.no1
#define TKCRDT0 TKCTRG0_bit.no0
#define TKCRSF0 TKCFLG0_bit.no0
#define TKCTOE00 TKCIOC01_bit.no0
#define TKCTOE01 TKCIOC01_bit.no1
#define TKCTOE02 TKCIOC01_bit.no2
#define TKCTOE03 TKCIOC01_bit.no3
#define TKCTOE04 TKCIOC01_bit.no4
#define TKCTOE05 TKCIOC01_bit.no5
#define TKCCE0 TKCCTL0_bit.no7
#define TKCTOF00 TKCTOF0_bit.no0
#define TKCTOF01 TKCTOF0_bit.no1
#define TKCTOF02 TKCTOF0_bit.no2
#define TKCTOF03 TKCTOF0_bit.no3
#define TKCTOF04 TKCTOF0_bit.no4
#define TKCTOF05 TKCTOF0_bit.no5

/*
 Interrupt vector addresses
 */
#endif
