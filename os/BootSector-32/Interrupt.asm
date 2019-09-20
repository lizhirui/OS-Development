[BITS 32]
EXTERN Interrupt_Handler_0,Interrupt_Handler_1,Interrupt_Handler_2,Interrupt_Handler_3,Interrupt_Handler_4,Interrupt_Handler_5,Interrupt_Handler_6,Interrupt_Handler_7,Interrupt_Handler_8,Interrupt_Handler_9,Interrupt_Handler_10,Interrupt_Handler_11,Interrupt_Handler_12,Interrupt_Handler_13,Interrupt_Handler_14,Interrupt_Handler_15,Interrupt_Handler_16,Interrupt_Handler_17,Interrupt_Handler_18,Interrupt_Handler_19,Interrupt_Handler_20,Interrupt_Handler_21,Interrupt_Handler_22,Interrupt_Handler_23,Interrupt_Handler_24,Interrupt_Handler_25,Interrupt_Handler_26,Interrupt_Handler_27,Interrupt_Handler_28,Interrupt_Handler_29,Interrupt_Handler_30,Interrupt_Handler_31,Interrupt_Handler_32,Interrupt_Handler_33,Interrupt_Handler_34,Interrupt_Handler_35,Interrupt_Handler_36,Interrupt_Handler_37,Interrupt_Handler_38,Interrupt_Handler_39,Interrupt_Handler_40,Interrupt_Handler_41,Interrupt_Handler_42,Interrupt_Handler_43,Interrupt_Handler_44,Interrupt_Handler_45,Interrupt_Handler_46,Interrupt_Handler_47,Interrupt_Handler_48,Interrupt_Handler_49,Interrupt_Handler_50,Interrupt_Handler_51,Interrupt_Handler_52,Interrupt_Handler_53,Interrupt_Handler_54,Interrupt_Handler_55,Interrupt_Handler_56,Interrupt_Handler_57,Interrupt_Handler_58,Interrupt_Handler_59,Interrupt_Handler_60,Interrupt_Handler_61,Interrupt_Handler_62,Interrupt_Handler_63,Interrupt_Handler_64,Interrupt_Handler_65,Interrupt_Handler_66,Interrupt_Handler_67,Interrupt_Handler_68,Interrupt_Handler_69,Interrupt_Handler_70,Interrupt_Handler_71,Interrupt_Handler_72,Interrupt_Handler_73,Interrupt_Handler_74,Interrupt_Handler_75,Interrupt_Handler_76,Interrupt_Handler_77,Interrupt_Handler_78,Interrupt_Handler_79,Interrupt_Handler_80,Interrupt_Handler_81,Interrupt_Handler_82,Interrupt_Handler_83,Interrupt_Handler_84,Interrupt_Handler_85,Interrupt_Handler_86,Interrupt_Handler_87,Interrupt_Handler_88,Interrupt_Handler_89,Interrupt_Handler_90,Interrupt_Handler_91,Interrupt_Handler_92,Interrupt_Handler_93,Interrupt_Handler_94,Interrupt_Handler_95,Interrupt_Handler_96,Interrupt_Handler_97,Interrupt_Handler_98,Interrupt_Handler_99,Interrupt_Handler_100,Interrupt_Handler_101,Interrupt_Handler_102,Interrupt_Handler_103,Interrupt_Handler_104,Interrupt_Handler_105,Interrupt_Handler_106,Interrupt_Handler_107,Interrupt_Handler_108,Interrupt_Handler_109,Interrupt_Handler_110,Interrupt_Handler_111,Interrupt_Handler_112,Interrupt_Handler_113,Interrupt_Handler_114,Interrupt_Handler_115,Interrupt_Handler_116,Interrupt_Handler_117,Interrupt_Handler_118,Interrupt_Handler_119,Interrupt_Handler_120,Interrupt_Handler_121,Interrupt_Handler_122,Interrupt_Handler_123,Interrupt_Handler_124,Interrupt_Handler_125,Interrupt_Handler_126,Interrupt_Handler_127,Interrupt_Handler_128,Interrupt_Handler_129,Interrupt_Handler_130,Interrupt_Handler_131,Interrupt_Handler_132,Interrupt_Handler_133,Interrupt_Handler_134,Interrupt_Handler_135,Interrupt_Handler_136,Interrupt_Handler_137,Interrupt_Handler_138,Interrupt_Handler_139,Interrupt_Handler_140,Interrupt_Handler_141,Interrupt_Handler_142,Interrupt_Handler_143,Interrupt_Handler_144,Interrupt_Handler_145,Interrupt_Handler_146,Interrupt_Handler_147,Interrupt_Handler_148,Interrupt_Handler_149,Interrupt_Handler_150,Interrupt_Handler_151,Interrupt_Handler_152,Interrupt_Handler_153,Interrupt_Handler_154,Interrupt_Handler_155,Interrupt_Handler_156,Interrupt_Handler_157,Interrupt_Handler_158,Interrupt_Handler_159,Interrupt_Handler_160,Interrupt_Handler_161,Interrupt_Handler_162,Interrupt_Handler_163,Interrupt_Handler_164,Interrupt_Handler_165,Interrupt_Handler_166,Interrupt_Handler_167,Interrupt_Handler_168,Interrupt_Handler_169,Interrupt_Handler_170,Interrupt_Handler_171,Interrupt_Handler_172,Interrupt_Handler_173,Interrupt_Handler_174,Interrupt_Handler_175,Interrupt_Handler_176,Interrupt_Handler_177,Interrupt_Handler_178,Interrupt_Handler_179,Interrupt_Handler_180,Interrupt_Handler_181,Interrupt_Handler_182,Interrupt_Handler_183,Interrupt_Handler_184,Interrupt_Handler_185,Interrupt_Handler_186,Interrupt_Handler_187,Interrupt_Handler_188,Interrupt_Handler_189,Interrupt_Handler_190,Interrupt_Handler_191,Interrupt_Handler_192,Interrupt_Handler_193,Interrupt_Handler_194,Interrupt_Handler_195,Interrupt_Handler_196,Interrupt_Handler_197,Interrupt_Handler_198,Interrupt_Handler_199,Interrupt_Handler_200,Interrupt_Handler_201,Interrupt_Handler_202,Interrupt_Handler_203,Interrupt_Handler_204,Interrupt_Handler_205,Interrupt_Handler_206,Interrupt_Handler_207,Interrupt_Handler_208,Interrupt_Handler_209,Interrupt_Handler_210,Interrupt_Handler_211,Interrupt_Handler_212,Interrupt_Handler_213,Interrupt_Handler_214,Interrupt_Handler_215,Interrupt_Handler_216,Interrupt_Handler_217,Interrupt_Handler_218,Interrupt_Handler_219,Interrupt_Handler_220,Interrupt_Handler_221,Interrupt_Handler_222,Interrupt_Handler_223,Interrupt_Handler_224,Interrupt_Handler_225,Interrupt_Handler_226,Interrupt_Handler_227,Interrupt_Handler_228,Interrupt_Handler_229,Interrupt_Handler_230,Interrupt_Handler_231,Interrupt_Handler_232,Interrupt_Handler_233,Interrupt_Handler_234,Interrupt_Handler_235,Interrupt_Handler_236,Interrupt_Handler_237,Interrupt_Handler_238,Interrupt_Handler_239,Interrupt_Handler_240,Interrupt_Handler_241,Interrupt_Handler_242,Interrupt_Handler_243,Interrupt_Handler_244,Interrupt_Handler_245,Interrupt_Handler_246,Interrupt_Handler_247,Interrupt_Handler_248,Interrupt_Handler_249,Interrupt_Handler_250,Interrupt_Handler_251,Interrupt_Handler_252,Interrupt_Handler_253,Interrupt_Handler_254,Interrupt_Handler_255
GLOBAL Interrupt_0,Interrupt_1,Interrupt_2,Interrupt_3,Interrupt_4,Interrupt_5,Interrupt_6,Interrupt_7,Interrupt_8,Interrupt_9,Interrupt_10,Interrupt_11,Interrupt_12,Interrupt_13,Interrupt_14,Interrupt_15,Interrupt_16,Interrupt_17,Interrupt_18,Interrupt_19,Interrupt_20,Interrupt_21,Interrupt_22,Interrupt_23,Interrupt_24,Interrupt_25,Interrupt_26,Interrupt_27,Interrupt_28,Interrupt_29,Interrupt_30,Interrupt_31,Interrupt_32,Interrupt_33,Interrupt_34,Interrupt_35,Interrupt_36,Interrupt_37,Interrupt_38,Interrupt_39,Interrupt_40,Interrupt_41,Interrupt_42,Interrupt_43,Interrupt_44,Interrupt_45,Interrupt_46,Interrupt_47,Interrupt_48,Interrupt_49,Interrupt_50,Interrupt_51,Interrupt_52,Interrupt_53,Interrupt_54,Interrupt_55,Interrupt_56,Interrupt_57,Interrupt_58,Interrupt_59,Interrupt_60,Interrupt_61,Interrupt_62,Interrupt_63,Interrupt_64,Interrupt_65,Interrupt_66,Interrupt_67,Interrupt_68,Interrupt_69,Interrupt_70,Interrupt_71,Interrupt_72,Interrupt_73,Interrupt_74,Interrupt_75,Interrupt_76,Interrupt_77,Interrupt_78,Interrupt_79,Interrupt_80,Interrupt_81,Interrupt_82,Interrupt_83,Interrupt_84,Interrupt_85,Interrupt_86,Interrupt_87,Interrupt_88,Interrupt_89,Interrupt_90,Interrupt_91,Interrupt_92,Interrupt_93,Interrupt_94,Interrupt_95,Interrupt_96,Interrupt_97,Interrupt_98,Interrupt_99,Interrupt_100,Interrupt_101,Interrupt_102,Interrupt_103,Interrupt_104,Interrupt_105,Interrupt_106,Interrupt_107,Interrupt_108,Interrupt_109,Interrupt_110,Interrupt_111,Interrupt_112,Interrupt_113,Interrupt_114,Interrupt_115,Interrupt_116,Interrupt_117,Interrupt_118,Interrupt_119,Interrupt_120,Interrupt_121,Interrupt_122,Interrupt_123,Interrupt_124,Interrupt_125,Interrupt_126,Interrupt_127,Interrupt_128,Interrupt_129,Interrupt_130,Interrupt_131,Interrupt_132,Interrupt_133,Interrupt_134,Interrupt_135,Interrupt_136,Interrupt_137,Interrupt_138,Interrupt_139,Interrupt_140,Interrupt_141,Interrupt_142,Interrupt_143,Interrupt_144,Interrupt_145,Interrupt_146,Interrupt_147,Interrupt_148,Interrupt_149,Interrupt_150,Interrupt_151,Interrupt_152,Interrupt_153,Interrupt_154,Interrupt_155,Interrupt_156,Interrupt_157,Interrupt_158,Interrupt_159,Interrupt_160,Interrupt_161,Interrupt_162,Interrupt_163,Interrupt_164,Interrupt_165,Interrupt_166,Interrupt_167,Interrupt_168,Interrupt_169,Interrupt_170,Interrupt_171,Interrupt_172,Interrupt_173,Interrupt_174,Interrupt_175,Interrupt_176,Interrupt_177,Interrupt_178,Interrupt_179,Interrupt_180,Interrupt_181,Interrupt_182,Interrupt_183,Interrupt_184,Interrupt_185,Interrupt_186,Interrupt_187,Interrupt_188,Interrupt_189,Interrupt_190,Interrupt_191,Interrupt_192,Interrupt_193,Interrupt_194,Interrupt_195,Interrupt_196,Interrupt_197,Interrupt_198,Interrupt_199,Interrupt_200,Interrupt_201,Interrupt_202,Interrupt_203,Interrupt_204,Interrupt_205,Interrupt_206,Interrupt_207,Interrupt_208,Interrupt_209,Interrupt_210,Interrupt_211,Interrupt_212,Interrupt_213,Interrupt_214,Interrupt_215,Interrupt_216,Interrupt_217,Interrupt_218,Interrupt_219,Interrupt_220,Interrupt_221,Interrupt_222,Interrupt_223,Interrupt_224,Interrupt_225,Interrupt_226,Interrupt_227,Interrupt_228,Interrupt_229,Interrupt_230,Interrupt_231,Interrupt_232,Interrupt_233,Interrupt_234,Interrupt_235,Interrupt_236,Interrupt_237,Interrupt_238,Interrupt_239,Interrupt_240,Interrupt_241,Interrupt_242,Interrupt_243,Interrupt_244,Interrupt_245,Interrupt_246,Interrupt_247,Interrupt_248,Interrupt_249,Interrupt_250,Interrupt_251,Interrupt_252,Interrupt_253,Interrupt_254,Interrupt_255

Interrupt_0:
	CALL Interrupt_Handler_0
	IRET

Interrupt_1:
	CALL Interrupt_Handler_1
	IRET

Interrupt_2:
	CALL Interrupt_Handler_2
	IRET

Interrupt_3:
	CALL Interrupt_Handler_3
	IRET

Interrupt_4:
	CALL Interrupt_Handler_4
	IRET

Interrupt_5:
	CALL Interrupt_Handler_5
	IRET

Interrupt_6:
	CALL Interrupt_Handler_6
	IRET

Interrupt_7:
	CALL Interrupt_Handler_7
	IRET

Interrupt_8:  
	CALL Interrupt_Handler_8
	IRET

Interrupt_9:
	CALL Interrupt_Handler_9
	IRET

Interrupt_10:
	CALL Interrupt_Handler_10
	IRET

Interrupt_11:
	CALL Interrupt_Handler_11
	IRET

Interrupt_12:
	CALL Interrupt_Handler_12
	IRET

Interrupt_13:
	CALL Interrupt_Handler_13
	IRET

Interrupt_14:
	CALL Interrupt_Handler_14
	IRET

Interrupt_15:
	CALL Interrupt_Handler_15
	IRET

Interrupt_16:
	CALL Interrupt_Handler_16
	IRET

Interrupt_17:
	CALL Interrupt_Handler_17
	IRET

Interrupt_18:
	CALL Interrupt_Handler_18
	IRET

Interrupt_19:
	CALL Interrupt_Handler_19
	IRET

Interrupt_20:
	CALL Interrupt_Handler_20
	IRET

Interrupt_21:
	CALL Interrupt_Handler_21
	IRET

Interrupt_22:
	CALL Interrupt_Handler_22
	IRET

Interrupt_23:
	CALL Interrupt_Handler_23
	IRET

Interrupt_24:
	CALL Interrupt_Handler_24
	IRET

Interrupt_25:
	CALL Interrupt_Handler_25
	IRET

Interrupt_26:
	CALL Interrupt_Handler_26
	IRET

Interrupt_27:
	CALL Interrupt_Handler_27
	IRET

Interrupt_28:
	CALL Interrupt_Handler_28
	IRET

Interrupt_29:
	CALL Interrupt_Handler_29
	IRET

Interrupt_30:
	CALL Interrupt_Handler_30
	IRET

Interrupt_31:
	CALL Interrupt_Handler_31
	IRET

Interrupt_32:
	CALL Interrupt_Handler_32
	IRET

Interrupt_33:
	CALL Interrupt_Handler_33
	IRET

Interrupt_34:
	CALL Interrupt_Handler_34
	IRET

Interrupt_35:
	CALL Interrupt_Handler_35
	IRET

Interrupt_36:
	CALL Interrupt_Handler_36
	IRET

Interrupt_37:
	CALL Interrupt_Handler_37
	IRET

Interrupt_38:
	CALL Interrupt_Handler_38
	IRET

Interrupt_39:
	CALL Interrupt_Handler_39
	IRET

Interrupt_40:
	CALL Interrupt_Handler_40
	IRET

Interrupt_41:
	CALL Interrupt_Handler_41
	IRET

Interrupt_42:
	CALL Interrupt_Handler_42
	IRET

Interrupt_43:
	CALL Interrupt_Handler_43
	IRET

Interrupt_44:
	CALL Interrupt_Handler_44
	IRET

Interrupt_45:
	CALL Interrupt_Handler_45
	IRET

Interrupt_46:
	CALL Interrupt_Handler_46
	IRET

Interrupt_47:
	CALL Interrupt_Handler_47
	IRET

Interrupt_48:
	CALL Interrupt_Handler_48
	IRET

Interrupt_49:
	CALL Interrupt_Handler_49
	IRET

Interrupt_50:
	CALL Interrupt_Handler_50
	IRET

Interrupt_51:
	CALL Interrupt_Handler_51
	IRET

Interrupt_52:
	CALL Interrupt_Handler_52
	IRET

Interrupt_53:
	CALL Interrupt_Handler_53
	IRET

Interrupt_54:
	CALL Interrupt_Handler_54
	IRET

Interrupt_55:
	CALL Interrupt_Handler_55
	IRET

Interrupt_56:
	CALL Interrupt_Handler_56
	IRET

Interrupt_57:
	CALL Interrupt_Handler_57
	IRET

Interrupt_58:
	CALL Interrupt_Handler_58
	IRET

Interrupt_59:
	CALL Interrupt_Handler_59
	IRET

Interrupt_60:
	CALL Interrupt_Handler_60
	IRET

Interrupt_61:
	CALL Interrupt_Handler_61
	IRET

Interrupt_62:
	CALL Interrupt_Handler_62
	IRET

Interrupt_63:
	CALL Interrupt_Handler_63
	IRET

Interrupt_64:
	CALL Interrupt_Handler_64
	IRET

Interrupt_65:
	CALL Interrupt_Handler_65
	IRET

Interrupt_66:
	CALL Interrupt_Handler_66
	IRET

Interrupt_67:
	CALL Interrupt_Handler_67
	IRET

Interrupt_68:
	CALL Interrupt_Handler_68
	IRET

Interrupt_69:
	CALL Interrupt_Handler_69
	IRET

Interrupt_70:
	CALL Interrupt_Handler_70
	IRET

Interrupt_71:
	CALL Interrupt_Handler_71
	IRET

Interrupt_72:
	CALL Interrupt_Handler_72
	IRET

Interrupt_73:
	CALL Interrupt_Handler_73
	IRET

Interrupt_74:
	CALL Interrupt_Handler_74
	IRET

Interrupt_75:
	CALL Interrupt_Handler_75
	IRET

Interrupt_76:
	CALL Interrupt_Handler_76
	IRET

Interrupt_77:
	CALL Interrupt_Handler_77
	IRET

Interrupt_78:
	CALL Interrupt_Handler_78
	IRET

Interrupt_79:
	CALL Interrupt_Handler_79
	IRET

Interrupt_80:
	CALL Interrupt_Handler_80
	IRET

Interrupt_81:
	CALL Interrupt_Handler_81
	IRET

Interrupt_82:
	CALL Interrupt_Handler_82
	IRET

Interrupt_83:
	CALL Interrupt_Handler_83
	IRET

Interrupt_84:
	CALL Interrupt_Handler_84
	IRET

Interrupt_85:
	CALL Interrupt_Handler_85
	IRET

Interrupt_86:
	CALL Interrupt_Handler_86
	IRET

Interrupt_87:
	CALL Interrupt_Handler_87
	IRET

Interrupt_88:
	CALL Interrupt_Handler_88
	IRET

Interrupt_89:
	CALL Interrupt_Handler_89
	IRET

Interrupt_90:
	CALL Interrupt_Handler_90
	IRET

Interrupt_91:
	CALL Interrupt_Handler_91
	IRET

Interrupt_92:
	CALL Interrupt_Handler_92
	IRET

Interrupt_93:
	CALL Interrupt_Handler_93
	IRET

Interrupt_94:
	CALL Interrupt_Handler_94
	IRET

Interrupt_95:
	CALL Interrupt_Handler_95
	IRET

Interrupt_96:
	CALL Interrupt_Handler_96
	IRET

Interrupt_97:
	CALL Interrupt_Handler_97
	IRET

Interrupt_98:
	CALL Interrupt_Handler_98
	IRET

Interrupt_99:
	CALL Interrupt_Handler_99
	IRET

Interrupt_100:
	CALL Interrupt_Handler_100
	IRET

Interrupt_101:
	CALL Interrupt_Handler_101
	IRET

Interrupt_102:
	CALL Interrupt_Handler_102
	IRET

Interrupt_103:
	CALL Interrupt_Handler_103
	IRET

Interrupt_104:
	CALL Interrupt_Handler_104
	IRET

Interrupt_105:
	CALL Interrupt_Handler_105
	IRET

Interrupt_106:
	CALL Interrupt_Handler_106
	IRET

Interrupt_107:
	CALL Interrupt_Handler_107
	IRET

Interrupt_108:
	CALL Interrupt_Handler_108
	IRET

Interrupt_109:
	CALL Interrupt_Handler_109
	IRET

Interrupt_110:
	CALL Interrupt_Handler_110
	IRET

Interrupt_111:
	CALL Interrupt_Handler_111
	IRET

Interrupt_112:
	CALL Interrupt_Handler_112
	IRET

Interrupt_113:
	CALL Interrupt_Handler_113
	IRET

Interrupt_114:
	CALL Interrupt_Handler_114
	IRET

Interrupt_115:
	CALL Interrupt_Handler_115
	IRET

Interrupt_116:
	CALL Interrupt_Handler_116
	IRET

Interrupt_117:
	CALL Interrupt_Handler_117
	IRET

Interrupt_118:
	CALL Interrupt_Handler_118
	IRET

Interrupt_119:
	CALL Interrupt_Handler_119
	IRET

Interrupt_120:
	CALL Interrupt_Handler_120
	IRET

Interrupt_121:
	CALL Interrupt_Handler_121
	IRET

Interrupt_122:
	CALL Interrupt_Handler_122
	IRET

Interrupt_123:
	CALL Interrupt_Handler_123
	IRET

Interrupt_124:
	CALL Interrupt_Handler_124
	IRET

Interrupt_125:
	CALL Interrupt_Handler_125
	IRET

Interrupt_126:
	CALL Interrupt_Handler_126
	IRET

Interrupt_127:
	CALL Interrupt_Handler_127
	IRET

Interrupt_128:
	CALL Interrupt_Handler_128
	IRET

Interrupt_129:
	CALL Interrupt_Handler_129
	IRET

Interrupt_130:
	CALL Interrupt_Handler_130
	IRET

Interrupt_131:
	CALL Interrupt_Handler_131
	IRET

Interrupt_132:
	CALL Interrupt_Handler_132
	IRET

Interrupt_133:
	CALL Interrupt_Handler_133
	IRET

Interrupt_134:
	CALL Interrupt_Handler_134
	IRET

Interrupt_135:
	CALL Interrupt_Handler_135
	IRET

Interrupt_136:
	CALL Interrupt_Handler_136
	IRET

Interrupt_137:
	CALL Interrupt_Handler_137
	IRET

Interrupt_138:
	CALL Interrupt_Handler_138
	IRET

Interrupt_139:
	CALL Interrupt_Handler_139
	IRET

Interrupt_140:
	CALL Interrupt_Handler_140
	IRET

Interrupt_141:
	CALL Interrupt_Handler_141
	IRET

Interrupt_142:
	CALL Interrupt_Handler_142
	IRET

Interrupt_143:
	CALL Interrupt_Handler_143
	IRET

Interrupt_144:
	CALL Interrupt_Handler_144
	IRET

Interrupt_145:
	CALL Interrupt_Handler_145
	IRET

Interrupt_146:
	CALL Interrupt_Handler_146
	IRET

Interrupt_147:
	CALL Interrupt_Handler_147
	IRET

Interrupt_148:
	CALL Interrupt_Handler_148
	IRET

Interrupt_149:
	CALL Interrupt_Handler_149
	IRET

Interrupt_150:
	CALL Interrupt_Handler_150
	IRET

Interrupt_151:
	CALL Interrupt_Handler_151
	IRET

Interrupt_152:
	CALL Interrupt_Handler_152
	IRET

Interrupt_153:
	CALL Interrupt_Handler_153
	IRET

Interrupt_154:
	CALL Interrupt_Handler_154
	IRET

Interrupt_155:
	CALL Interrupt_Handler_155
	IRET

Interrupt_156:
	CALL Interrupt_Handler_156
	IRET

Interrupt_157:
	CALL Interrupt_Handler_157
	IRET

Interrupt_158:
	CALL Interrupt_Handler_158
	IRET

Interrupt_159:
	CALL Interrupt_Handler_159
	IRET

Interrupt_160:
	CALL Interrupt_Handler_160
	IRET

Interrupt_161:
	CALL Interrupt_Handler_161
	IRET

Interrupt_162:
	CALL Interrupt_Handler_162
	IRET

Interrupt_163:
	CALL Interrupt_Handler_163
	IRET

Interrupt_164:
	CALL Interrupt_Handler_164
	IRET

Interrupt_165:
	CALL Interrupt_Handler_165
	IRET

Interrupt_166:
	CALL Interrupt_Handler_166
	IRET

Interrupt_167:
	CALL Interrupt_Handler_167
	IRET

Interrupt_168:
	CALL Interrupt_Handler_168
	IRET

Interrupt_169:
	CALL Interrupt_Handler_169
	IRET

Interrupt_170:
	CALL Interrupt_Handler_170
	IRET

Interrupt_171:
	CALL Interrupt_Handler_171
	IRET

Interrupt_172:
	CALL Interrupt_Handler_172
	IRET

Interrupt_173:
	CALL Interrupt_Handler_173
	IRET

Interrupt_174:
	CALL Interrupt_Handler_174
	IRET

Interrupt_175:
	CALL Interrupt_Handler_175
	IRET

Interrupt_176:
	CALL Interrupt_Handler_176
	IRET

Interrupt_177:
	CALL Interrupt_Handler_177
	IRET

Interrupt_178:
	CALL Interrupt_Handler_178
	IRET

Interrupt_179:
	CALL Interrupt_Handler_179
	IRET

Interrupt_180:
	CALL Interrupt_Handler_180
	IRET

Interrupt_181:
	CALL Interrupt_Handler_181
	IRET

Interrupt_182:
	CALL Interrupt_Handler_182
	IRET

Interrupt_183:
	CALL Interrupt_Handler_183
	IRET

Interrupt_184:
	CALL Interrupt_Handler_184
	IRET

Interrupt_185:
	CALL Interrupt_Handler_185
	IRET

Interrupt_186:
	CALL Interrupt_Handler_186
	IRET

Interrupt_187:
	CALL Interrupt_Handler_187
	IRET

Interrupt_188:
	CALL Interrupt_Handler_188
	IRET

Interrupt_189:
	CALL Interrupt_Handler_189
	IRET

Interrupt_190:
	CALL Interrupt_Handler_190
	IRET

Interrupt_191:
	CALL Interrupt_Handler_191
	IRET

Interrupt_192:
	CALL Interrupt_Handler_192
	IRET

Interrupt_193:
	CALL Interrupt_Handler_193
	IRET

Interrupt_194:
	CALL Interrupt_Handler_194
	IRET

Interrupt_195:
	CALL Interrupt_Handler_195
	IRET

Interrupt_196:
	CALL Interrupt_Handler_196
	IRET

Interrupt_197:
	CALL Interrupt_Handler_197
	IRET

Interrupt_198:
	CALL Interrupt_Handler_198
	IRET

Interrupt_199:
	CALL Interrupt_Handler_199
	IRET

Interrupt_200:
	CALL Interrupt_Handler_200
	IRET

Interrupt_201:
	CALL Interrupt_Handler_201
	IRET

Interrupt_202:
	CALL Interrupt_Handler_202
	IRET

Interrupt_203:
	CALL Interrupt_Handler_203
	IRET

Interrupt_204:
	CALL Interrupt_Handler_204
	IRET

Interrupt_205:
	CALL Interrupt_Handler_205
	IRET

Interrupt_206:
	CALL Interrupt_Handler_206
	IRET

Interrupt_207:
	CALL Interrupt_Handler_207
	IRET

Interrupt_208:
	CALL Interrupt_Handler_208
	IRET

Interrupt_209:
	CALL Interrupt_Handler_209
	IRET

Interrupt_210:
	CALL Interrupt_Handler_210
	IRET

Interrupt_211:
	CALL Interrupt_Handler_211
	IRET

Interrupt_212:
	CALL Interrupt_Handler_212
	IRET

Interrupt_213:
	CALL Interrupt_Handler_213
	IRET

Interrupt_214:
	CALL Interrupt_Handler_214
	IRET

Interrupt_215:
	CALL Interrupt_Handler_215
	IRET

Interrupt_216:
	CALL Interrupt_Handler_216
	IRET

Interrupt_217:
	CALL Interrupt_Handler_217
	IRET

Interrupt_218:
	CALL Interrupt_Handler_218
	IRET

Interrupt_219:
	CALL Interrupt_Handler_219
	IRET

Interrupt_220:
	CALL Interrupt_Handler_220
	IRET

Interrupt_221:
	CALL Interrupt_Handler_221
	IRET

Interrupt_222:
	CALL Interrupt_Handler_222
	IRET

Interrupt_223:
	CALL Interrupt_Handler_223
	IRET

Interrupt_224:
	CALL Interrupt_Handler_224
	IRET

Interrupt_225:
	CALL Interrupt_Handler_225
	IRET

Interrupt_226:
	CALL Interrupt_Handler_226
	IRET

Interrupt_227:
	CALL Interrupt_Handler_227
	IRET

Interrupt_228:
	CALL Interrupt_Handler_228
	IRET

Interrupt_229:
	CALL Interrupt_Handler_229
	IRET

Interrupt_230:
	CALL Interrupt_Handler_230
	IRET

Interrupt_231:
	CALL Interrupt_Handler_231
	IRET

Interrupt_232:
	CALL Interrupt_Handler_232
	IRET

Interrupt_233:
	CALL Interrupt_Handler_233
	IRET

Interrupt_234:
	CALL Interrupt_Handler_234
	IRET

Interrupt_235:
	CALL Interrupt_Handler_235
	IRET

Interrupt_236:
	CALL Interrupt_Handler_236
	IRET

Interrupt_237:
	CALL Interrupt_Handler_237
	IRET

Interrupt_238:
	CALL Interrupt_Handler_238
	IRET

Interrupt_239:
	CALL Interrupt_Handler_239
	IRET

Interrupt_240:
	CALL Interrupt_Handler_240
	IRET

Interrupt_241:
	CALL Interrupt_Handler_241
	IRET

Interrupt_242:
	CALL Interrupt_Handler_242
	IRET

Interrupt_243:
	CALL Interrupt_Handler_243
	IRET

Interrupt_244:
	CALL Interrupt_Handler_244
	IRET

Interrupt_245:
	CALL Interrupt_Handler_245
	IRET

Interrupt_246:
	CALL Interrupt_Handler_246
	IRET

Interrupt_247:
	CALL Interrupt_Handler_247
	IRET

Interrupt_248:
	CALL Interrupt_Handler_248
	IRET

Interrupt_249:
	CALL Interrupt_Handler_249
	IRET

Interrupt_250:
	CALL Interrupt_Handler_250
	IRET

Interrupt_251:
	CALL Interrupt_Handler_251
	IRET

Interrupt_252:
	CALL Interrupt_Handler_252
	IRET

Interrupt_253:
	CALL Interrupt_Handler_253
	IRET

Interrupt_254:
	CALL Interrupt_Handler_254
	IRET

Interrupt_255:
	CALL Interrupt_Handler_255
	IRET