#include "common.h"
#include "Interrupt.h"
#include "idt.h"
#include "video.h"
#include "ICH7Driver/ICH7_8259.h"

void Interrupt_Handler_0()
{
	Video_printf((uchar *)"Interrupt_Handler_0:Don't div 0!\n");
	while(1);
}

void Interrupt_Handler_1()
{
	Video_printf((uchar *)"Interrupt_Handler_1:\n");
	while(1);
}

void Interrupt_Handler_2()
{
	Video_printf((uchar *)"Interrupt_Handler_2:\n");
	while(1);
}

void Interrupt_Handler_3()
{
	Video_printf((uchar *)"Interrupt_Handler_3:\n");
	while(1);
}

void Interrupt_Handler_4()
{
	Video_printf((uchar *)"Interrupt_Handler_4:\n");
	while(1);
}

void Interrupt_Handler_5()
{
	Video_printf((uchar *)"Interrupt_Handler_5:\n");
	while(1);
}

void Interrupt_Handler_6()
{
	Video_printf((uchar *)"Interrupt_Handler_6:Fault:Invalid Opcode!\n");
	while(1);
}

void Interrupt_Handler_7()
{
	Video_printf((uchar *)"Interrupt_Handler_7:\n");
	while(1);
}

void Interrupt_Handler_8()
{
	//Video_printf((uchar *)"Interrupt_Handler_8:Internal Timer:%d\n",ReadSysConfigTable32(0));
	WriteSysConfigTable32(0,ReadSysConfigTable32(0) + 1);
	ICH7_8259_Master_Handler_End();
	//while(1);
}

void Interrupt_Handler_9()
{
	Video_printf((uchar *)"Interrupt_Handler_9:\n");
	while(1);
}

void Interrupt_Handler_10()
{
	Video_printf((uchar *)"Interrupt_Handler_10:\n");
	while(1);
}

void Interrupt_Handler_11()
{
	Video_printf((uchar *)"Interrupt_Handler_11:\n");
	while(1);
}

void Interrupt_Handler_12()
{
	Video_printf((uchar *)"Interrupt_Handler_12:\n");
	while(1);
}

void Interrupt_Handler_13()
{
	Video_printf((uchar *)"Interrupt_Handler_13:\n");
	while(1);
}

void Interrupt_Handler_14()
{
	Video_printf((uchar *)"Interrupt_Handler_14:\n");
	while(1);
}

void Interrupt_Handler_15()
{
	Video_printf((uchar *)"Interrupt_Handler_15:\n");
	while(1);
}

void Interrupt_Handler_16()
{
	Video_printf((uchar *)"Interrupt_Handler_16:\n");
	while(1);
}

void Interrupt_Handler_17()
{
	Video_printf((uchar *)"Interrupt_Handler_17:\n");
	while(1);
}

void Interrupt_Handler_18()
{
	Video_printf((uchar *)"Interrupt_Handler_18:\n");
	while(1);
}

void Interrupt_Handler_19()
{
	Video_printf((uchar *)"Interrupt_Handler_19:\n");
	while(1);
}

void Interrupt_Handler_20()
{
	Video_printf((uchar *)"Interrupt_Handler_20:\n");
	while(1);
}

void Interrupt_Handler_21()
{
	Video_printf((uchar *)"Interrupt_Handler_21:\n");
	while(1);
}

void Interrupt_Handler_22()
{
	Video_printf((uchar *)"Interrupt_Handler_22:\n");
	while(1);
}

void Interrupt_Handler_23()
{
	Video_printf((uchar *)"Interrupt_Handler_23:\n");
	while(1);
}

void Interrupt_Handler_24()
{
	Video_printf((uchar *)"Interrupt_Handler_24:\n");
	while(1);
}

void Interrupt_Handler_25()
{
	Video_printf((uchar *)"Interrupt_Handler_25:\n");
	while(1);
}

void Interrupt_Handler_26()
{
	Video_printf((uchar *)"Interrupt_Handler_26:\n");
	while(1);
}

void Interrupt_Handler_27()
{
	Video_printf((uchar *)"Interrupt_Handler_27:\n");
	while(1);
}

void Interrupt_Handler_28()
{
	Video_printf((uchar *)"Interrupt_Handler_28:\n");
	while(1);
}

void Interrupt_Handler_29()
{
	Video_printf((uchar *)"Interrupt_Handler_29:\n");
	while(1);
}

void Interrupt_Handler_30()
{
	Video_printf((uchar *)"Interrupt_Handler_30:\n");
	while(1);
}

void Interrupt_Handler_31()
{
	Video_printf((uchar *)"Interrupt_Handler_31:\n");
	while(1);
}

void Interrupt_Handler_32()
{
	Video_printf((uchar *)"Interrupt_Handler_32:\n");
	while(1);
}

void Interrupt_Handler_33()
{
	Video_printf((uchar *)"Interrupt_Handler_33:\n");
	while(1);
}

void Interrupt_Handler_34()
{
	Video_printf((uchar *)"Interrupt_Handler_34:\n");
	while(1);
}

void Interrupt_Handler_35()
{
	Video_printf((uchar *)"Interrupt_Handler_35:\n");
	while(1);
}

void Interrupt_Handler_36()
{
	Video_printf((uchar *)"Interrupt_Handler_36:\n");
	while(1);
}

void Interrupt_Handler_37()
{
	Video_printf((uchar *)"Interrupt_Handler_37:\n");
	while(1);
}

void Interrupt_Handler_38()
{
	Video_printf((uchar *)"Interrupt_Handler_38:\n");
	while(1);
}

void Interrupt_Handler_39()
{
	Video_printf((uchar *)"Interrupt_Handler_39:\n");
	while(1);
}

void Interrupt_Handler_40()
{
	Video_printf((uchar *)"Interrupt_Handler_40:\n");
	while(1);
}

void Interrupt_Handler_41()
{
	Video_printf((uchar *)"Interrupt_Handler_41:\n");
	while(1);
}

void Interrupt_Handler_42()
{
	Video_printf((uchar *)"Interrupt_Handler_42:\n");
	while(1);
}

void Interrupt_Handler_43()
{
	Video_printf((uchar *)"Interrupt_Handler_43:\n");
	while(1);
}

void Interrupt_Handler_44()
{
	Video_printf((uchar *)"Interrupt_Handler_44:\n");
	while(1);
}

void Interrupt_Handler_45()
{
	Video_printf((uchar *)"Interrupt_Handler_45:\n");
	while(1);
}

void Interrupt_Handler_46()
{
	Video_printf((uchar *)"Interrupt_Handler_46:\n");
	while(1);
}

void Interrupt_Handler_47()
{
	Video_printf((uchar *)"Interrupt_Handler_47:\n");
	while(1);
}

void Interrupt_Handler_48()
{
	Video_printf((uchar *)"Interrupt_Handler_48:\n");
	while(1);
}

void Interrupt_Handler_49()
{
	Video_printf((uchar *)"Interrupt_Handler_49:\n");
	while(1);
}

void Interrupt_Handler_50()
{
	Video_printf((uchar *)"Interrupt_Handler_50:\n");
	while(1);
}

void Interrupt_Handler_51()
{
	Video_printf((uchar *)"Interrupt_Handler_51:\n");
	while(1);
}

void Interrupt_Handler_52()
{
	Video_printf((uchar *)"Interrupt_Handler_52:\n");
	while(1);
}

void Interrupt_Handler_53()
{
	Video_printf((uchar *)"Interrupt_Handler_53:\n");
	while(1);
}

void Interrupt_Handler_54()
{
	Video_printf((uchar *)"Interrupt_Handler_54:\n");
	while(1);
}

void Interrupt_Handler_55()
{
	Video_printf((uchar *)"Interrupt_Handler_55:\n");
	while(1);
}

void Interrupt_Handler_56()
{
	Video_printf((uchar *)"Interrupt_Handler_56:\n");
	while(1);
}

void Interrupt_Handler_57()
{
	Video_printf((uchar *)"Interrupt_Handler_57:\n");
	while(1);
}

void Interrupt_Handler_58()
{
	Video_printf((uchar *)"Interrupt_Handler_58:\n");
	while(1);
}

void Interrupt_Handler_59()
{
	Video_printf((uchar *)"Interrupt_Handler_59:\n");
	while(1);
}

void Interrupt_Handler_60()
{
	Video_printf((uchar *)"Interrupt_Handler_60:\n");
	while(1);
}

void Interrupt_Handler_61()
{
	Video_printf((uchar *)"Interrupt_Handler_61:\n");
	while(1);
}

void Interrupt_Handler_62()
{
	Video_printf((uchar *)"Interrupt_Handler_62:\n");
	while(1);
}

void Interrupt_Handler_63()
{
	Video_printf((uchar *)"Interrupt_Handler_63:\n");
	while(1);
}

void Interrupt_Handler_64()
{
	Video_printf((uchar *)"Interrupt_Handler_64:\n");
	while(1);
}

void Interrupt_Handler_65()
{
	Video_printf((uchar *)"Interrupt_Handler_65:\n");
	while(1);
}

void Interrupt_Handler_66()
{
	Video_printf((uchar *)"Interrupt_Handler_66:\n");
	while(1);
}

void Interrupt_Handler_67()
{
	Video_printf((uchar *)"Interrupt_Handler_67:\n");
	while(1);
}

void Interrupt_Handler_68()
{
	Video_printf((uchar *)"Interrupt_Handler_68:\n");
	while(1);
}

void Interrupt_Handler_69()
{
	Video_printf((uchar *)"Interrupt_Handler_69:\n");
	while(1);
}

void Interrupt_Handler_70()
{
	Video_printf((uchar *)"Interrupt_Handler_70:\n");
	while(1);
}

void Interrupt_Handler_71()
{
	Video_printf((uchar *)"Interrupt_Handler_71:\n");
	while(1);
}

void Interrupt_Handler_72()
{
	Video_printf((uchar *)"Interrupt_Handler_72:\n");
	while(1);
}

void Interrupt_Handler_73()
{
	Video_printf((uchar *)"Interrupt_Handler_73:\n");
	while(1);
}

void Interrupt_Handler_74()
{
	Video_printf((uchar *)"Interrupt_Handler_74:\n");
	while(1);
}

void Interrupt_Handler_75()
{
	Video_printf((uchar *)"Interrupt_Handler_75:\n");
	while(1);
}

void Interrupt_Handler_76()
{
	Video_printf((uchar *)"Interrupt_Handler_76:\n");
	while(1);
}

void Interrupt_Handler_77()
{
	Video_printf((uchar *)"Interrupt_Handler_77:\n");
	while(1);
}

void Interrupt_Handler_78()
{
	Video_printf((uchar *)"Interrupt_Handler_78:\n");
	while(1);
}

void Interrupt_Handler_79()
{
	Video_printf((uchar *)"Interrupt_Handler_79:\n");
	while(1);
}

void Interrupt_Handler_80()
{
	Video_printf((uchar *)"Interrupt_Handler_80:\n");
	while(1);
}

void Interrupt_Handler_81()
{
	Video_printf((uchar *)"Interrupt_Handler_81:\n");
	while(1);
}

void Interrupt_Handler_82()
{
	Video_printf((uchar *)"Interrupt_Handler_82:\n");
	while(1);
}

void Interrupt_Handler_83()
{
	Video_printf((uchar *)"Interrupt_Handler_83:\n");
	while(1);
}

void Interrupt_Handler_84()
{
	Video_printf((uchar *)"Interrupt_Handler_84:\n");
	while(1);
}

void Interrupt_Handler_85()
{
	Video_printf((uchar *)"Interrupt_Handler_85:\n");
	while(1);
}

void Interrupt_Handler_86()
{
	Video_printf((uchar *)"Interrupt_Handler_86:\n");
	while(1);
}

void Interrupt_Handler_87()
{
	Video_printf((uchar *)"Interrupt_Handler_87:\n");
	while(1);
}

void Interrupt_Handler_88()
{
	Video_printf((uchar *)"Interrupt_Handler_88:\n");
	while(1);
}

void Interrupt_Handler_89()
{
	Video_printf((uchar *)"Interrupt_Handler_89:\n");
	while(1);
}

void Interrupt_Handler_90()
{
	Video_printf((uchar *)"Interrupt_Handler_90:\n");
	while(1);
}

void Interrupt_Handler_91()
{
	Video_printf((uchar *)"Interrupt_Handler_91:\n");
	while(1);
}

void Interrupt_Handler_92()
{
	Video_printf((uchar *)"Interrupt_Handler_92:\n");
	while(1);
}

void Interrupt_Handler_93()
{
	Video_printf((uchar *)"Interrupt_Handler_93:\n");
	while(1);
}

void Interrupt_Handler_94()
{
	Video_printf((uchar *)"Interrupt_Handler_94:\n");
	while(1);
}

void Interrupt_Handler_95()
{
	Video_printf((uchar *)"Interrupt_Handler_95:\n");
	while(1);
}

void Interrupt_Handler_96()
{
	Video_printf((uchar *)"Interrupt_Handler_96:\n");
	while(1);
}

void Interrupt_Handler_97()
{
	Video_printf((uchar *)"Interrupt_Handler_97:\n");
	while(1);
}

void Interrupt_Handler_98()
{
	Video_printf((uchar *)"Interrupt_Handler_98:\n");
	while(1);
}

void Interrupt_Handler_99()
{
	Video_printf((uchar *)"Interrupt_Handler_99:\n");
	while(1);
}

void Interrupt_Handler_100()
{
	Video_printf((uchar *)"Interrupt_Handler_100:\n");
	while(1);
}

void Interrupt_Handler_101()
{
	Video_printf((uchar *)"Interrupt_Handler_101:\n");
	while(1);
}

void Interrupt_Handler_102()
{
	Video_printf((uchar *)"Interrupt_Handler_102:\n");
	while(1);
}

void Interrupt_Handler_103()
{
	Video_printf((uchar *)"Interrupt_Handler_103:\n");
	while(1);
}

void Interrupt_Handler_104()
{
	Video_printf((uchar *)"Interrupt_Handler_104:\n");
	while(1);
}

void Interrupt_Handler_105()
{
	Video_printf((uchar *)"Interrupt_Handler_105:\n");
	while(1);
}

void Interrupt_Handler_106()
{
	Video_printf((uchar *)"Interrupt_Handler_106:\n");
	while(1);
}

void Interrupt_Handler_107()
{
	Video_printf((uchar *)"Interrupt_Handler_107:\n");
	while(1);
}

void Interrupt_Handler_108()
{
	Video_printf((uchar *)"Interrupt_Handler_108:\n");
	while(1);
}

void Interrupt_Handler_109()
{
	Video_printf((uchar *)"Interrupt_Handler_109:\n");
	while(1);
}

void Interrupt_Handler_110()
{
	Video_printf((uchar *)"Interrupt_Handler_110:\n");
	while(1);
}

void Interrupt_Handler_111()
{
	Video_printf((uchar *)"Interrupt_Handler_111:\n");
	while(1);
}

void Interrupt_Handler_112()
{
	Video_printf((uchar *)"Interrupt_Handler_112:\n");
	while(1);
}

void Interrupt_Handler_113()
{
	Video_printf((uchar *)"Interrupt_Handler_113:\n");
	while(1);
}

void Interrupt_Handler_114()
{
	Video_printf((uchar *)"Interrupt_Handler_114:\n");
	while(1);
}

void Interrupt_Handler_115()
{
	Video_printf((uchar *)"Interrupt_Handler_115:\n");
	while(1);
}

void Interrupt_Handler_116()
{
	Video_printf((uchar *)"Interrupt_Handler_116:\n");
	while(1);
}

void Interrupt_Handler_117()
{
	Video_printf((uchar *)"Interrupt_Handler_117:\n");
	while(1);
}

void Interrupt_Handler_118()
{
	Video_printf((uchar *)"Interrupt_Handler_118:\n");
	while(1);
}

void Interrupt_Handler_119()
{
	Video_printf((uchar *)"Interrupt_Handler_119:\n");
	while(1);
}

void Interrupt_Handler_120()
{
	Video_printf((uchar *)"Interrupt_Handler_120:\n");
	while(1);
}

void Interrupt_Handler_121()
{
	Video_printf((uchar *)"Interrupt_Handler_121:\n");
	while(1);
}

void Interrupt_Handler_122()
{
	Video_printf((uchar *)"Interrupt_Handler_122:\n");
	while(1);
}

void Interrupt_Handler_123()
{
	Video_printf((uchar *)"Interrupt_Handler_123:\n");
	while(1);
}

void Interrupt_Handler_124()
{
	Video_printf((uchar *)"Interrupt_Handler_124:\n");
	while(1);
}

void Interrupt_Handler_125()
{
	Video_printf((uchar *)"Interrupt_Handler_125:\n");
	while(1);
}

void Interrupt_Handler_126()
{
	Video_printf((uchar *)"Interrupt_Handler_126:\n");
	while(1);
}

void Interrupt_Handler_127()
{
	Video_printf((uchar *)"Interrupt_Handler_127:\n");
	while(1);
}

void Interrupt_Handler_128()
{
	Video_printf((uchar *)"Interrupt_Handler_128:\n");
	while(1);
}

void Interrupt_Handler_129()
{
	Video_printf((uchar *)"Interrupt_Handler_129:\n");
	while(1);
}

void Interrupt_Handler_130()
{
	Video_printf((uchar *)"Interrupt_Handler_130:\n");
	while(1);
}

void Interrupt_Handler_131()
{
	Video_printf((uchar *)"Interrupt_Handler_131:\n");
	while(1);
}

void Interrupt_Handler_132()
{
	Video_printf((uchar *)"Interrupt_Handler_132:\n");
	while(1);
}

void Interrupt_Handler_133()
{
	Video_printf((uchar *)"Interrupt_Handler_133:\n");
	while(1);
}

void Interrupt_Handler_134()
{
	Video_printf((uchar *)"Interrupt_Handler_134:\n");
	while(1);
}

void Interrupt_Handler_135()
{
	Video_printf((uchar *)"Interrupt_Handler_135:\n");
	while(1);
}

void Interrupt_Handler_136()
{
	Video_printf((uchar *)"Interrupt_Handler_136:\n");
	while(1);
}

void Interrupt_Handler_137()
{
	Video_printf((uchar *)"Interrupt_Handler_137:\n");
	while(1);
}

void Interrupt_Handler_138()
{
	Video_printf((uchar *)"Interrupt_Handler_138:\n");
	while(1);
}

void Interrupt_Handler_139()
{
	Video_printf((uchar *)"Interrupt_Handler_139:\n");
	while(1);
}

void Interrupt_Handler_140()
{
	Video_printf((uchar *)"Interrupt_Handler_140:\n");
	while(1);
}

void Interrupt_Handler_141()
{
	Video_printf((uchar *)"Interrupt_Handler_141:\n");
	while(1);
}

void Interrupt_Handler_142()
{
	Video_printf((uchar *)"Interrupt_Handler_142:\n");
	while(1);
}

void Interrupt_Handler_143()
{
	Video_printf((uchar *)"Interrupt_Handler_143:\n");
	while(1);
}

void Interrupt_Handler_144()
{
	Video_printf((uchar *)"Interrupt_Handler_144:\n");
	while(1);
}

void Interrupt_Handler_145()
{
	Video_printf((uchar *)"Interrupt_Handler_145:\n");
	while(1);
}

void Interrupt_Handler_146()
{
	Video_printf((uchar *)"Interrupt_Handler_146:\n");
	while(1);
}

void Interrupt_Handler_147()
{
	Video_printf((uchar *)"Interrupt_Handler_147:\n");
	while(1);
}

void Interrupt_Handler_148()
{
	Video_printf((uchar *)"Interrupt_Handler_148:\n");
	while(1);
}

void Interrupt_Handler_149()
{
	Video_printf((uchar *)"Interrupt_Handler_149:\n");
	while(1);
}

void Interrupt_Handler_150()
{
	Video_printf((uchar *)"Interrupt_Handler_150:\n");
	while(1);
}

void Interrupt_Handler_151()
{
	Video_printf((uchar *)"Interrupt_Handler_151:\n");
	while(1);
}

void Interrupt_Handler_152()
{
	Video_printf((uchar *)"Interrupt_Handler_152:\n");
	while(1);
}

void Interrupt_Handler_153()
{
	Video_printf((uchar *)"Interrupt_Handler_153:\n");
	while(1);
}

void Interrupt_Handler_154()
{
	Video_printf((uchar *)"Interrupt_Handler_154:\n");
	while(1);
}

void Interrupt_Handler_155()
{
	Video_printf((uchar *)"Interrupt_Handler_155:\n");
	while(1);
}

void Interrupt_Handler_156()
{
	Video_printf((uchar *)"Interrupt_Handler_156:\n");
	while(1);
}

void Interrupt_Handler_157()
{
	Video_printf((uchar *)"Interrupt_Handler_157:\n");
	while(1);
}

void Interrupt_Handler_158()
{
	Video_printf((uchar *)"Interrupt_Handler_158:\n");
	while(1);
}

void Interrupt_Handler_159()
{
	Video_printf((uchar *)"Interrupt_Handler_159:\n");
	while(1);
}

void Interrupt_Handler_160()
{
	Video_printf((uchar *)"Interrupt_Handler_160:\n");
	while(1);
}

void Interrupt_Handler_161()
{
	Video_printf((uchar *)"Interrupt_Handler_161:\n");
	while(1);
}

void Interrupt_Handler_162()
{
	Video_printf((uchar *)"Interrupt_Handler_162:\n");
	while(1);
}

void Interrupt_Handler_163()
{
	Video_printf((uchar *)"Interrupt_Handler_163:\n");
	while(1);
}

void Interrupt_Handler_164()
{
	Video_printf((uchar *)"Interrupt_Handler_164:\n");
	while(1);
}

void Interrupt_Handler_165()
{
	Video_printf((uchar *)"Interrupt_Handler_165:\n");
	while(1);
}

void Interrupt_Handler_166()
{
	Video_printf((uchar *)"Interrupt_Handler_166:\n");
	while(1);
}

void Interrupt_Handler_167()
{
	Video_printf((uchar *)"Interrupt_Handler_167:\n");
	while(1);
}

void Interrupt_Handler_168()
{
	Video_printf((uchar *)"Interrupt_Handler_168:\n");
	while(1);
}

void Interrupt_Handler_169()
{
	Video_printf((uchar *)"Interrupt_Handler_169:\n");
	while(1);
}

void Interrupt_Handler_170()
{
	Video_printf((uchar *)"Interrupt_Handler_170:\n");
	while(1);
}

void Interrupt_Handler_171()
{
	Video_printf((uchar *)"Interrupt_Handler_171:\n");
	while(1);
}

void Interrupt_Handler_172()
{
	Video_printf((uchar *)"Interrupt_Handler_172:\n");
	while(1);
}

void Interrupt_Handler_173()
{
	Video_printf((uchar *)"Interrupt_Handler_173:\n");
	while(1);
}

void Interrupt_Handler_174()
{
	Video_printf((uchar *)"Interrupt_Handler_174:\n");
	while(1);
}

void Interrupt_Handler_175()
{
	Video_printf((uchar *)"Interrupt_Handler_175:\n");
	while(1);
}

void Interrupt_Handler_176()
{
	Video_printf((uchar *)"Interrupt_Handler_176:\n");
	while(1);
}

void Interrupt_Handler_177()
{
	Video_printf((uchar *)"Interrupt_Handler_177:\n");
	while(1);
}

void Interrupt_Handler_178()
{
	Video_printf((uchar *)"Interrupt_Handler_178:\n");
	while(1);
}

void Interrupt_Handler_179()
{
	Video_printf((uchar *)"Interrupt_Handler_179:\n");
	while(1);
}

void Interrupt_Handler_180()
{
	Video_printf((uchar *)"Interrupt_Handler_180:\n");
	while(1);
}

void Interrupt_Handler_181()
{
	Video_printf((uchar *)"Interrupt_Handler_181:\n");
	while(1);
}

void Interrupt_Handler_182()
{
	Video_printf((uchar *)"Interrupt_Handler_182:\n");
	while(1);
}

void Interrupt_Handler_183()
{
	Video_printf((uchar *)"Interrupt_Handler_183:\n");
	while(1);
}

void Interrupt_Handler_184()
{
	Video_printf((uchar *)"Interrupt_Handler_184:\n");
	while(1);
}

void Interrupt_Handler_185()
{
	Video_printf((uchar *)"Interrupt_Handler_185:\n");
	while(1);
}

void Interrupt_Handler_186()
{
	Video_printf((uchar *)"Interrupt_Handler_186:\n");
	while(1);
}

void Interrupt_Handler_187()
{
	Video_printf((uchar *)"Interrupt_Handler_187:\n");
	while(1);
}

void Interrupt_Handler_188()
{
	Video_printf((uchar *)"Interrupt_Handler_188:\n");
	while(1);
}

void Interrupt_Handler_189()
{
	Video_printf((uchar *)"Interrupt_Handler_189:\n");
	while(1);
}

void Interrupt_Handler_190()
{
	Video_printf((uchar *)"Interrupt_Handler_190:\n");
	while(1);
}

void Interrupt_Handler_191()
{
	Video_printf((uchar *)"Interrupt_Handler_191:\n");
	while(1);
}

void Interrupt_Handler_192()
{
	Video_printf((uchar *)"Interrupt_Handler_192:\n");
	while(1);
}

void Interrupt_Handler_193()
{
	Video_printf((uchar *)"Interrupt_Handler_193:\n");
	while(1);
}

void Interrupt_Handler_194()
{
	Video_printf((uchar *)"Interrupt_Handler_194:\n");
	while(1);
}

void Interrupt_Handler_195()
{
	Video_printf((uchar *)"Interrupt_Handler_195:\n");
	while(1);
}

void Interrupt_Handler_196()
{
	Video_printf((uchar *)"Interrupt_Handler_196:\n");
	while(1);
}

void Interrupt_Handler_197()
{
	Video_printf((uchar *)"Interrupt_Handler_197:\n");
	while(1);
}

void Interrupt_Handler_198()
{
	Video_printf((uchar *)"Interrupt_Handler_198:\n");
	while(1);
}

void Interrupt_Handler_199()
{
	Video_printf((uchar *)"Interrupt_Handler_199:\n");
	while(1);
}

void Interrupt_Handler_200()
{
	Video_printf((uchar *)"Interrupt_Handler_200:\n");
	while(1);
}

void Interrupt_Handler_201()
{
	Video_printf((uchar *)"Interrupt_Handler_201:\n");
	while(1);
}

void Interrupt_Handler_202()
{
	Video_printf((uchar *)"Interrupt_Handler_202:\n");
	while(1);
}

void Interrupt_Handler_203()
{
	Video_printf((uchar *)"Interrupt_Handler_203:\n");
	while(1);
}

void Interrupt_Handler_204()
{
	Video_printf((uchar *)"Interrupt_Handler_204:\n");
	while(1);
}

void Interrupt_Handler_205()
{
	Video_printf((uchar *)"Interrupt_Handler_205:\n");
	while(1);
}

void Interrupt_Handler_206()
{
	Video_printf((uchar *)"Interrupt_Handler_206:\n");
	while(1);
}

void Interrupt_Handler_207()
{
	Video_printf((uchar *)"Interrupt_Handler_207:\n");
	while(1);
}

void Interrupt_Handler_208()
{
	Video_printf((uchar *)"Interrupt_Handler_208:\n");
	while(1);
}

void Interrupt_Handler_209()
{
	Video_printf((uchar *)"Interrupt_Handler_209:\n");
	while(1);
}

void Interrupt_Handler_210()
{
	Video_printf((uchar *)"Interrupt_Handler_210:\n");
	while(1);
}

void Interrupt_Handler_211()
{
	Video_printf((uchar *)"Interrupt_Handler_211:\n");
	while(1);
}

void Interrupt_Handler_212()
{
	Video_printf((uchar *)"Interrupt_Handler_212:\n");
	while(1);
}

void Interrupt_Handler_213()
{
	Video_printf((uchar *)"Interrupt_Handler_213:\n");
	while(1);
}

void Interrupt_Handler_214()
{
	Video_printf((uchar *)"Interrupt_Handler_214:\n");
	while(1);
}

void Interrupt_Handler_215()
{
	Video_printf((uchar *)"Interrupt_Handler_215:\n");
	while(1);
}

void Interrupt_Handler_216()
{
	Video_printf((uchar *)"Interrupt_Handler_216:\n");
	while(1);
}

void Interrupt_Handler_217()
{
	Video_printf((uchar *)"Interrupt_Handler_217:\n");
	while(1);
}

void Interrupt_Handler_218()
{
	Video_printf((uchar *)"Interrupt_Handler_218:\n");
	while(1);
}

void Interrupt_Handler_219()
{
	Video_printf((uchar *)"Interrupt_Handler_219:\n");
	while(1);
}

void Interrupt_Handler_220()
{
	Video_printf((uchar *)"Interrupt_Handler_220:\n");
	while(1);
}

void Interrupt_Handler_221()
{
	Video_printf((uchar *)"Interrupt_Handler_221:\n");
	while(1);
}

void Interrupt_Handler_222()
{
	Video_printf((uchar *)"Interrupt_Handler_222:\n");
	while(1);
}

void Interrupt_Handler_223()
{
	Video_printf((uchar *)"Interrupt_Handler_223:\n");
	while(1);
}

void Interrupt_Handler_224()
{
	Video_printf((uchar *)"Interrupt_Handler_224:\n");
	while(1);
}

void Interrupt_Handler_225()
{
	Video_printf((uchar *)"Interrupt_Handler_225:\n");
	while(1);
}

void Interrupt_Handler_226()
{
	Video_printf((uchar *)"Interrupt_Handler_226:\n");
	while(1);
}

void Interrupt_Handler_227()
{
	Video_printf((uchar *)"Interrupt_Handler_227:\n");
	while(1);
}

void Interrupt_Handler_228()
{
	Video_printf((uchar *)"Interrupt_Handler_228:\n");
	while(1);
}

void Interrupt_Handler_229()
{
	Video_printf((uchar *)"Interrupt_Handler_229:\n");
	while(1);
}

void Interrupt_Handler_230()
{
	Video_printf((uchar *)"Interrupt_Handler_230:\n");
	while(1);
}

void Interrupt_Handler_231()
{
	Video_printf((uchar *)"Interrupt_Handler_231:\n");
	while(1);
}

void Interrupt_Handler_232()
{
	Video_printf((uchar *)"Interrupt_Handler_232:\n");
	while(1);
}

void Interrupt_Handler_233()
{
	Video_printf((uchar *)"Interrupt_Handler_233:\n");
	while(1);
}

void Interrupt_Handler_234()
{
	Video_printf((uchar *)"Interrupt_Handler_234:\n");
	while(1);
}

void Interrupt_Handler_235()
{
	Video_printf((uchar *)"Interrupt_Handler_235:\n");
	while(1);
}

void Interrupt_Handler_236()
{
	Video_printf((uchar *)"Interrupt_Handler_236:\n");
	while(1);
}

void Interrupt_Handler_237()
{
	Video_printf((uchar *)"Interrupt_Handler_237:\n");
	while(1);
}

void Interrupt_Handler_238()
{
	Video_printf((uchar *)"Interrupt_Handler_238:\n");
	while(1);
}

void Interrupt_Handler_239()
{
	Video_printf((uchar *)"Interrupt_Handler_239:\n");
	while(1);
}

void Interrupt_Handler_240()
{
	Video_printf((uchar *)"Interrupt_Handler_240:\n");
	while(1);
}

void Interrupt_Handler_241()
{
	Video_printf((uchar *)"Interrupt_Handler_241:\n");
	while(1);
}

void Interrupt_Handler_242()
{
	Video_printf((uchar *)"Interrupt_Handler_242:\n");
	while(1);
}

void Interrupt_Handler_243()
{
	Video_printf((uchar *)"Interrupt_Handler_243:\n");
	while(1);
}

void Interrupt_Handler_244()
{
	Video_printf((uchar *)"Interrupt_Handler_244:\n");
	while(1);
}

void Interrupt_Handler_245()
{
	Video_printf((uchar *)"Interrupt_Handler_245:\n");
	while(1);
}

void Interrupt_Handler_246()
{
	Video_printf((uchar *)"Interrupt_Handler_246:\n");
	while(1);
}

void Interrupt_Handler_247()
{
	Video_printf((uchar *)"Interrupt_Handler_247:\n");
	while(1);
}

void Interrupt_Handler_248()
{
	Video_printf((uchar *)"Interrupt_Handler_248:\n");
	while(1);
}

void Interrupt_Handler_249()
{
	Video_printf((uchar *)"Interrupt_Handler_249:\n");
	while(1);
}

void Interrupt_Handler_250()
{
	Video_printf((uchar *)"Interrupt_Handler_250:\n");
	while(1);
}

void Interrupt_Handler_251()
{
	Video_printf((uchar *)"Interrupt_Handler_251:\n");
	while(1);
}

void Interrupt_Handler_252()
{
	Video_printf((uchar *)"Interrupt_Handler_252:\n");
	while(1);
}

void Interrupt_Handler_253()
{
	Video_printf((uchar *)"Interrupt_Handler_253:\n");
	while(1);
}

void Interrupt_Handler_254()
{
	Video_printf((uchar *)"Interrupt_Handler_254:\n");
	while(1);
}

void Interrupt_Handler_255()
{
	Video_printf((uchar *)"Interrupt_Handler_255:\n");
	while(1);
}

void Interrupt_Init()//÷–∂œ≥ı ºªØ
{
	SegmentSelector segsel;
	IDT_SegmentDescriptor idts;

	segsel.ID = 1;
	segsel.Attr = SegmentSelector_DPL0 | SegmentSelector_GDT;
	idts.SegSel = segsel;
	idts.Attr = IDT_SegmentDescriptor_DPL0 | IDT_SegmentDescriptor_32Bit | IDT_SegmentDescriptor_Enable;

	idts.Offset = (uint)(&Interrupt_0);
	IDT_WriteIDT(0,idts);
	
	idts.Offset = (uint)(&Interrupt_1);
	IDT_WriteIDT(1,idts);

	idts.Offset = (uint)(&Interrupt_2);
	IDT_WriteIDT(2,idts);

	idts.Offset = (uint)(&Interrupt_3);
	IDT_WriteIDT(3,idts);

	idts.Offset = (uint)(&Interrupt_4);
	IDT_WriteIDT(4,idts);

	idts.Offset = (uint)(&Interrupt_5);
	IDT_WriteIDT(5,idts);

	idts.Offset = (uint)(&Interrupt_6);
	IDT_WriteIDT(6,idts);

	idts.Offset = (uint)(&Interrupt_7);
	IDT_WriteIDT(7,idts);

	idts.Offset = (uint)(&Interrupt_8);
	IDT_WriteIDT(8,idts);

	idts.Offset = (uint)(&Interrupt_9);
	IDT_WriteIDT(9,idts);

	idts.Offset = (uint)(&Interrupt_10);
	IDT_WriteIDT(10,idts);

	idts.Offset = (uint)(&Interrupt_11);
	IDT_WriteIDT(11,idts);

	idts.Offset = (uint)(&Interrupt_12);
	IDT_WriteIDT(12,idts);

	idts.Offset = (uint)(&Interrupt_13);
	IDT_WriteIDT(13,idts);

	idts.Offset = (uint)(&Interrupt_14);
	IDT_WriteIDT(14,idts);

	idts.Offset = (uint)(&Interrupt_15);
	IDT_WriteIDT(15,idts);

	idts.Offset = (uint)(&Interrupt_16);
	IDT_WriteIDT(16,idts);

	idts.Offset = (uint)(&Interrupt_17);
	IDT_WriteIDT(17,idts);

	idts.Offset = (uint)(&Interrupt_18);
	IDT_WriteIDT(18,idts);

	idts.Offset = (uint)(&Interrupt_19);
	IDT_WriteIDT(19,idts);

	idts.Offset = (uint)(&Interrupt_20);
	IDT_WriteIDT(20,idts);

	idts.Offset = (uint)(&Interrupt_21);
	IDT_WriteIDT(21,idts);

	idts.Offset = (uint)(&Interrupt_22);
	IDT_WriteIDT(22,idts);

	idts.Offset = (uint)(&Interrupt_23);
	IDT_WriteIDT(23,idts);

	idts.Offset = (uint)(&Interrupt_24);
	IDT_WriteIDT(24,idts);

	idts.Offset = (uint)(&Interrupt_25);
	IDT_WriteIDT(25,idts);

	idts.Offset = (uint)(&Interrupt_26);
	IDT_WriteIDT(26,idts);

	idts.Offset = (uint)(&Interrupt_27);
	IDT_WriteIDT(27,idts);

	idts.Offset = (uint)(&Interrupt_28);
	IDT_WriteIDT(28,idts);

	idts.Offset = (uint)(&Interrupt_29);
	IDT_WriteIDT(29,idts);

	idts.Offset = (uint)(&Interrupt_30);
	IDT_WriteIDT(30,idts);

	idts.Offset = (uint)(&Interrupt_31);
	IDT_WriteIDT(31,idts);

	idts.Offset = (uint)(&Interrupt_32);
	IDT_WriteIDT(32,idts);

	idts.Offset = (uint)(&Interrupt_33);
	IDT_WriteIDT(33,idts);

	idts.Offset = (uint)(&Interrupt_34);
	IDT_WriteIDT(34,idts);

	idts.Offset = (uint)(&Interrupt_35);
	IDT_WriteIDT(35,idts);

	idts.Offset = (uint)(&Interrupt_36);
	IDT_WriteIDT(36,idts);

	idts.Offset = (uint)(&Interrupt_37);
	IDT_WriteIDT(37,idts);

	idts.Offset = (uint)(&Interrupt_38);
	IDT_WriteIDT(38,idts);

	idts.Offset = (uint)(&Interrupt_39);
	IDT_WriteIDT(39,idts);

	idts.Offset = (uint)(&Interrupt_40);
	IDT_WriteIDT(40,idts);

	idts.Offset = (uint)(&Interrupt_41);
	IDT_WriteIDT(41,idts);

	idts.Offset = (uint)(&Interrupt_42);
	IDT_WriteIDT(42,idts);

	idts.Offset = (uint)(&Interrupt_43);
	IDT_WriteIDT(43,idts);

	idts.Offset = (uint)(&Interrupt_44);
	IDT_WriteIDT(44,idts);

	idts.Offset = (uint)(&Interrupt_45);
	IDT_WriteIDT(45,idts);

	idts.Offset = (uint)(&Interrupt_46);
	IDT_WriteIDT(46,idts);

	idts.Offset = (uint)(&Interrupt_47);
	IDT_WriteIDT(47,idts);

	idts.Offset = (uint)(&Interrupt_48);
	IDT_WriteIDT(48,idts);

	idts.Offset = (uint)(&Interrupt_49);
	IDT_WriteIDT(49,idts);

	idts.Offset = (uint)(&Interrupt_50);
	IDT_WriteIDT(50,idts);

	idts.Offset = (uint)(&Interrupt_51);
	IDT_WriteIDT(51,idts);

	idts.Offset = (uint)(&Interrupt_52);
	IDT_WriteIDT(52,idts);

	idts.Offset = (uint)(&Interrupt_53);
	IDT_WriteIDT(53,idts);

	idts.Offset = (uint)(&Interrupt_54);
	IDT_WriteIDT(54,idts);

	idts.Offset = (uint)(&Interrupt_55);
	IDT_WriteIDT(55,idts);

	idts.Offset = (uint)(&Interrupt_56);
	IDT_WriteIDT(56,idts);

	idts.Offset = (uint)(&Interrupt_57);
	IDT_WriteIDT(57,idts);

	idts.Offset = (uint)(&Interrupt_58);
	IDT_WriteIDT(58,idts);

	idts.Offset = (uint)(&Interrupt_59);
	IDT_WriteIDT(59,idts);

	idts.Offset = (uint)(&Interrupt_60);
	IDT_WriteIDT(60,idts);

	idts.Offset = (uint)(&Interrupt_61);
	IDT_WriteIDT(61,idts);

	idts.Offset = (uint)(&Interrupt_62);
	IDT_WriteIDT(62,idts);

	idts.Offset = (uint)(&Interrupt_63);
	IDT_WriteIDT(63,idts);

	idts.Offset = (uint)(&Interrupt_64);
	IDT_WriteIDT(64,idts);

	idts.Offset = (uint)(&Interrupt_65);
	IDT_WriteIDT(65,idts);

	idts.Offset = (uint)(&Interrupt_66);
	IDT_WriteIDT(66,idts);

	idts.Offset = (uint)(&Interrupt_67);
	IDT_WriteIDT(67,idts);

	idts.Offset = (uint)(&Interrupt_68);
	IDT_WriteIDT(68,idts);

	idts.Offset = (uint)(&Interrupt_69);
	IDT_WriteIDT(69,idts);

	idts.Offset = (uint)(&Interrupt_70);
	IDT_WriteIDT(70,idts);

	idts.Offset = (uint)(&Interrupt_71);
	IDT_WriteIDT(71,idts);

	idts.Offset = (uint)(&Interrupt_72);
	IDT_WriteIDT(72,idts);

	idts.Offset = (uint)(&Interrupt_73);
	IDT_WriteIDT(73,idts);

	idts.Offset = (uint)(&Interrupt_74);
	IDT_WriteIDT(74,idts);

	idts.Offset = (uint)(&Interrupt_75);
	IDT_WriteIDT(75,idts);

	idts.Offset = (uint)(&Interrupt_76);
	IDT_WriteIDT(76,idts);

	idts.Offset = (uint)(&Interrupt_77);
	IDT_WriteIDT(77,idts);

	idts.Offset = (uint)(&Interrupt_78);
	IDT_WriteIDT(78,idts);

	idts.Offset = (uint)(&Interrupt_79);
	IDT_WriteIDT(79,idts);

	idts.Offset = (uint)(&Interrupt_80);
	IDT_WriteIDT(80,idts);

	idts.Offset = (uint)(&Interrupt_81);
	IDT_WriteIDT(81,idts);

	idts.Offset = (uint)(&Interrupt_82);
	IDT_WriteIDT(82,idts);

	idts.Offset = (uint)(&Interrupt_83);
	IDT_WriteIDT(83,idts);

	idts.Offset = (uint)(&Interrupt_84);
	IDT_WriteIDT(84,idts);

	idts.Offset = (uint)(&Interrupt_85);
	IDT_WriteIDT(85,idts);

	idts.Offset = (uint)(&Interrupt_86);
	IDT_WriteIDT(86,idts);

	idts.Offset = (uint)(&Interrupt_87);
	IDT_WriteIDT(87,idts);

	idts.Offset = (uint)(&Interrupt_88);
	IDT_WriteIDT(88,idts);

	idts.Offset = (uint)(&Interrupt_89);
	IDT_WriteIDT(89,idts);

	idts.Offset = (uint)(&Interrupt_90);
	IDT_WriteIDT(90,idts);

	idts.Offset = (uint)(&Interrupt_91);
	IDT_WriteIDT(91,idts);

	idts.Offset = (uint)(&Interrupt_92);
	IDT_WriteIDT(92,idts);

	idts.Offset = (uint)(&Interrupt_93);
	IDT_WriteIDT(93,idts);

	idts.Offset = (uint)(&Interrupt_94);
	IDT_WriteIDT(94,idts);

	idts.Offset = (uint)(&Interrupt_95);
	IDT_WriteIDT(95,idts);

	idts.Offset = (uint)(&Interrupt_96);
	IDT_WriteIDT(96,idts);

	idts.Offset = (uint)(&Interrupt_97);
	IDT_WriteIDT(97,idts);

	idts.Offset = (uint)(&Interrupt_98);
	IDT_WriteIDT(98,idts);

	idts.Offset = (uint)(&Interrupt_99);
	IDT_WriteIDT(99,idts);

	idts.Offset = (uint)(&Interrupt_100);
	IDT_WriteIDT(100,idts);

	idts.Offset = (uint)(&Interrupt_101);
	IDT_WriteIDT(101,idts);

	idts.Offset = (uint)(&Interrupt_102);
	IDT_WriteIDT(102,idts);

	idts.Offset = (uint)(&Interrupt_103);
	IDT_WriteIDT(103,idts);

	idts.Offset = (uint)(&Interrupt_104);
	IDT_WriteIDT(104,idts);

	idts.Offset = (uint)(&Interrupt_105);
	IDT_WriteIDT(105,idts);

	idts.Offset = (uint)(&Interrupt_106);
	IDT_WriteIDT(106,idts);

	idts.Offset = (uint)(&Interrupt_107);
	IDT_WriteIDT(107,idts);

	idts.Offset = (uint)(&Interrupt_108);
	IDT_WriteIDT(108,idts);

	idts.Offset = (uint)(&Interrupt_109);
	IDT_WriteIDT(109,idts);

	idts.Offset = (uint)(&Interrupt_110);
	IDT_WriteIDT(110,idts);

	idts.Offset = (uint)(&Interrupt_111);
	IDT_WriteIDT(111,idts);

	idts.Offset = (uint)(&Interrupt_112);
	IDT_WriteIDT(112,idts);

	idts.Offset = (uint)(&Interrupt_113);
	IDT_WriteIDT(113,idts);

	idts.Offset = (uint)(&Interrupt_114);
	IDT_WriteIDT(114,idts);

	idts.Offset = (uint)(&Interrupt_115);
	IDT_WriteIDT(115,idts);

	idts.Offset = (uint)(&Interrupt_116);
	IDT_WriteIDT(116,idts);

	idts.Offset = (uint)(&Interrupt_117);
	IDT_WriteIDT(117,idts);

	idts.Offset = (uint)(&Interrupt_118);
	IDT_WriteIDT(118,idts);

	idts.Offset = (uint)(&Interrupt_119);
	IDT_WriteIDT(119,idts);

	idts.Offset = (uint)(&Interrupt_120);
	IDT_WriteIDT(120,idts);

	idts.Offset = (uint)(&Interrupt_121);
	IDT_WriteIDT(121,idts);

	idts.Offset = (uint)(&Interrupt_122);
	IDT_WriteIDT(122,idts);

	idts.Offset = (uint)(&Interrupt_123);
	IDT_WriteIDT(123,idts);

	idts.Offset = (uint)(&Interrupt_124);
	IDT_WriteIDT(124,idts);

	idts.Offset = (uint)(&Interrupt_125);
	IDT_WriteIDT(125,idts);

	idts.Offset = (uint)(&Interrupt_126);
	IDT_WriteIDT(126,idts);

	idts.Offset = (uint)(&Interrupt_127);
	IDT_WriteIDT(127,idts);

	idts.Offset = (uint)(&Interrupt_128);
	IDT_WriteIDT(128,idts);

	idts.Offset = (uint)(&Interrupt_129);
	IDT_WriteIDT(129,idts);

	idts.Offset = (uint)(&Interrupt_130);
	IDT_WriteIDT(130,idts);

	idts.Offset = (uint)(&Interrupt_131);
	IDT_WriteIDT(131,idts);

	idts.Offset = (uint)(&Interrupt_132);
	IDT_WriteIDT(132,idts);

	idts.Offset = (uint)(&Interrupt_133);
	IDT_WriteIDT(133,idts);

	idts.Offset = (uint)(&Interrupt_134);
	IDT_WriteIDT(134,idts);

	idts.Offset = (uint)(&Interrupt_135);
	IDT_WriteIDT(135,idts);

	idts.Offset = (uint)(&Interrupt_136);
	IDT_WriteIDT(136,idts);

	idts.Offset = (uint)(&Interrupt_137);
	IDT_WriteIDT(137,idts);

	idts.Offset = (uint)(&Interrupt_138);
	IDT_WriteIDT(138,idts);

	idts.Offset = (uint)(&Interrupt_139);
	IDT_WriteIDT(139,idts);

	idts.Offset = (uint)(&Interrupt_140);
	IDT_WriteIDT(140,idts);

	idts.Offset = (uint)(&Interrupt_141);
	IDT_WriteIDT(141,idts);

	idts.Offset = (uint)(&Interrupt_142);
	IDT_WriteIDT(142,idts);

	idts.Offset = (uint)(&Interrupt_143);
	IDT_WriteIDT(143,idts);

	idts.Offset = (uint)(&Interrupt_144);
	IDT_WriteIDT(144,idts);

	idts.Offset = (uint)(&Interrupt_145);
	IDT_WriteIDT(145,idts);

	idts.Offset = (uint)(&Interrupt_146);
	IDT_WriteIDT(146,idts);

	idts.Offset = (uint)(&Interrupt_147);
	IDT_WriteIDT(147,idts);

	idts.Offset = (uint)(&Interrupt_148);
	IDT_WriteIDT(148,idts);

	idts.Offset = (uint)(&Interrupt_149);
	IDT_WriteIDT(149,idts);

	idts.Offset = (uint)(&Interrupt_150);
	IDT_WriteIDT(150,idts);

	idts.Offset = (uint)(&Interrupt_151);
	IDT_WriteIDT(151,idts);

	idts.Offset = (uint)(&Interrupt_152);
	IDT_WriteIDT(152,idts);

	idts.Offset = (uint)(&Interrupt_153);
	IDT_WriteIDT(153,idts);

	idts.Offset = (uint)(&Interrupt_154);
	IDT_WriteIDT(154,idts);

	idts.Offset = (uint)(&Interrupt_155);
	IDT_WriteIDT(155,idts);

	idts.Offset = (uint)(&Interrupt_156);
	IDT_WriteIDT(156,idts);

	idts.Offset = (uint)(&Interrupt_157);
	IDT_WriteIDT(157,idts);

	idts.Offset = (uint)(&Interrupt_158);
	IDT_WriteIDT(158,idts);

	idts.Offset = (uint)(&Interrupt_159);
	IDT_WriteIDT(159,idts);

	idts.Offset = (uint)(&Interrupt_160);
	IDT_WriteIDT(160,idts);

	idts.Offset = (uint)(&Interrupt_161);
	IDT_WriteIDT(161,idts);

	idts.Offset = (uint)(&Interrupt_162);
	IDT_WriteIDT(162,idts);

	idts.Offset = (uint)(&Interrupt_163);
	IDT_WriteIDT(163,idts);

	idts.Offset = (uint)(&Interrupt_164);
	IDT_WriteIDT(164,idts);

	idts.Offset = (uint)(&Interrupt_165);
	IDT_WriteIDT(165,idts);

	idts.Offset = (uint)(&Interrupt_166);
	IDT_WriteIDT(166,idts);

	idts.Offset = (uint)(&Interrupt_167);
	IDT_WriteIDT(167,idts);

	idts.Offset = (uint)(&Interrupt_168);
	IDT_WriteIDT(168,idts);

	idts.Offset = (uint)(&Interrupt_169);
	IDT_WriteIDT(169,idts);

	idts.Offset = (uint)(&Interrupt_170);
	IDT_WriteIDT(170,idts);

	idts.Offset = (uint)(&Interrupt_171);
	IDT_WriteIDT(171,idts);

	idts.Offset = (uint)(&Interrupt_172);
	IDT_WriteIDT(172,idts);

	idts.Offset = (uint)(&Interrupt_173);
	IDT_WriteIDT(173,idts);

	idts.Offset = (uint)(&Interrupt_174);
	IDT_WriteIDT(174,idts);

	idts.Offset = (uint)(&Interrupt_175);
	IDT_WriteIDT(175,idts);

	idts.Offset = (uint)(&Interrupt_176);
	IDT_WriteIDT(176,idts);

	idts.Offset = (uint)(&Interrupt_177);
	IDT_WriteIDT(177,idts);

	idts.Offset = (uint)(&Interrupt_178);
	IDT_WriteIDT(178,idts);

	idts.Offset = (uint)(&Interrupt_179);
	IDT_WriteIDT(179,idts);

	idts.Offset = (uint)(&Interrupt_180);
	IDT_WriteIDT(180,idts);

	idts.Offset = (uint)(&Interrupt_181);
	IDT_WriteIDT(181,idts);

	idts.Offset = (uint)(&Interrupt_182);
	IDT_WriteIDT(182,idts);

	idts.Offset = (uint)(&Interrupt_183);
	IDT_WriteIDT(183,idts);

	idts.Offset = (uint)(&Interrupt_184);
	IDT_WriteIDT(184,idts);

	idts.Offset = (uint)(&Interrupt_185);
	IDT_WriteIDT(185,idts);

	idts.Offset = (uint)(&Interrupt_186);
	IDT_WriteIDT(186,idts);

	idts.Offset = (uint)(&Interrupt_187);
	IDT_WriteIDT(187,idts);

	idts.Offset = (uint)(&Interrupt_188);
	IDT_WriteIDT(188,idts);

	idts.Offset = (uint)(&Interrupt_189);
	IDT_WriteIDT(189,idts);

	idts.Offset = (uint)(&Interrupt_190);
	IDT_WriteIDT(190,idts);

	idts.Offset = (uint)(&Interrupt_191);
	IDT_WriteIDT(191,idts);

	idts.Offset = (uint)(&Interrupt_192);
	IDT_WriteIDT(192,idts);

	idts.Offset = (uint)(&Interrupt_193);
	IDT_WriteIDT(193,idts);

	idts.Offset = (uint)(&Interrupt_194);
	IDT_WriteIDT(194,idts);

	idts.Offset = (uint)(&Interrupt_195);
	IDT_WriteIDT(195,idts);

	idts.Offset = (uint)(&Interrupt_196);
	IDT_WriteIDT(196,idts);

	idts.Offset = (uint)(&Interrupt_197);
	IDT_WriteIDT(197,idts);

	idts.Offset = (uint)(&Interrupt_198);
	IDT_WriteIDT(198,idts);

	idts.Offset = (uint)(&Interrupt_199);
	IDT_WriteIDT(199,idts);

	idts.Offset = (uint)(&Interrupt_200);
	IDT_WriteIDT(200,idts);

	idts.Offset = (uint)(&Interrupt_201);
	IDT_WriteIDT(201,idts);

	idts.Offset = (uint)(&Interrupt_202);
	IDT_WriteIDT(202,idts);

	idts.Offset = (uint)(&Interrupt_203);
	IDT_WriteIDT(203,idts);

	idts.Offset = (uint)(&Interrupt_204);
	IDT_WriteIDT(204,idts);

	idts.Offset = (uint)(&Interrupt_205);
	IDT_WriteIDT(205,idts);

	idts.Offset = (uint)(&Interrupt_206);
	IDT_WriteIDT(206,idts);

	idts.Offset = (uint)(&Interrupt_207);
	IDT_WriteIDT(207,idts);

	idts.Offset = (uint)(&Interrupt_208);
	IDT_WriteIDT(208,idts);

	idts.Offset = (uint)(&Interrupt_209);
	IDT_WriteIDT(209,idts);

	idts.Offset = (uint)(&Interrupt_210);
	IDT_WriteIDT(210,idts);

	idts.Offset = (uint)(&Interrupt_211);
	IDT_WriteIDT(211,idts);

	idts.Offset = (uint)(&Interrupt_212);
	IDT_WriteIDT(212,idts);

	idts.Offset = (uint)(&Interrupt_213);
	IDT_WriteIDT(213,idts);

	idts.Offset = (uint)(&Interrupt_214);
	IDT_WriteIDT(214,idts);

	idts.Offset = (uint)(&Interrupt_215);
	IDT_WriteIDT(215,idts);

	idts.Offset = (uint)(&Interrupt_216);
	IDT_WriteIDT(216,idts);

	idts.Offset = (uint)(&Interrupt_217);
	IDT_WriteIDT(217,idts);

	idts.Offset = (uint)(&Interrupt_218);
	IDT_WriteIDT(218,idts);

	idts.Offset = (uint)(&Interrupt_219);
	IDT_WriteIDT(219,idts);

	idts.Offset = (uint)(&Interrupt_220);
	IDT_WriteIDT(220,idts);

	idts.Offset = (uint)(&Interrupt_221);
	IDT_WriteIDT(221,idts);

	idts.Offset = (uint)(&Interrupt_222);
	IDT_WriteIDT(222,idts);

	idts.Offset = (uint)(&Interrupt_223);
	IDT_WriteIDT(223,idts);

	idts.Offset = (uint)(&Interrupt_224);
	IDT_WriteIDT(224,idts);

	idts.Offset = (uint)(&Interrupt_225);
	IDT_WriteIDT(225,idts);

	idts.Offset = (uint)(&Interrupt_226);
	IDT_WriteIDT(226,idts);

	idts.Offset = (uint)(&Interrupt_227);
	IDT_WriteIDT(227,idts);

	idts.Offset = (uint)(&Interrupt_228);
	IDT_WriteIDT(228,idts);

	idts.Offset = (uint)(&Interrupt_229);
	IDT_WriteIDT(229,idts);

	idts.Offset = (uint)(&Interrupt_230);
	IDT_WriteIDT(230,idts);

	idts.Offset = (uint)(&Interrupt_231);
	IDT_WriteIDT(231,idts);

	idts.Offset = (uint)(&Interrupt_232);
	IDT_WriteIDT(232,idts);

	idts.Offset = (uint)(&Interrupt_233);
	IDT_WriteIDT(233,idts);

	idts.Offset = (uint)(&Interrupt_234);
	IDT_WriteIDT(234,idts);

	idts.Offset = (uint)(&Interrupt_235);
	IDT_WriteIDT(235,idts);

	idts.Offset = (uint)(&Interrupt_236);
	IDT_WriteIDT(236,idts);

	idts.Offset = (uint)(&Interrupt_237);
	IDT_WriteIDT(237,idts);

	idts.Offset = (uint)(&Interrupt_238);
	IDT_WriteIDT(238,idts);

	idts.Offset = (uint)(&Interrupt_239);
	IDT_WriteIDT(239,idts);

	idts.Offset = (uint)(&Interrupt_240);
	IDT_WriteIDT(240,idts);

	idts.Offset = (uint)(&Interrupt_241);
	IDT_WriteIDT(241,idts);

	idts.Offset = (uint)(&Interrupt_242);
	IDT_WriteIDT(242,idts);

	idts.Offset = (uint)(&Interrupt_243);
	IDT_WriteIDT(243,idts);

	idts.Offset = (uint)(&Interrupt_244);
	IDT_WriteIDT(244,idts);

	idts.Offset = (uint)(&Interrupt_245);
	IDT_WriteIDT(245,idts);

	idts.Offset = (uint)(&Interrupt_246);
	IDT_WriteIDT(246,idts);

	idts.Offset = (uint)(&Interrupt_247);
	IDT_WriteIDT(247,idts);

	idts.Offset = (uint)(&Interrupt_248);
	IDT_WriteIDT(248,idts);

	idts.Offset = (uint)(&Interrupt_249);
	IDT_WriteIDT(249,idts);

	idts.Offset = (uint)(&Interrupt_250);
	IDT_WriteIDT(250,idts);

	idts.Offset = (uint)(&Interrupt_251);
	IDT_WriteIDT(251,idts);

	idts.Offset = (uint)(&Interrupt_252);
	IDT_WriteIDT(252,idts);

	idts.Offset = (uint)(&Interrupt_253);
	IDT_WriteIDT(253,idts);

	idts.Offset = (uint)(&Interrupt_254);
	IDT_WriteIDT(254,idts);

	idts.Offset = (uint)(&Interrupt_255);
	IDT_WriteIDT(255,idts);
}