/* Copyright 2016 Stephen Bösebeck
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#undef KEYMAP_GERMAN_MAC_ISO



// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ ^ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ß │ ´ │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ Q │ W │ E │ R │ T │ Z │ U │ I │ O │ P │ Ü │ + │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Ö │ Ä │ # │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ < │ Y │ X │ C │ V │ B │ N │ M │ , │ . │ - │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#undef DE_CIRC
#undef DE_1
#undef DE_2
#undef DE_3
#undef DE_4
#undef DE_5
#undef DE_6
#undef DE_7
#undef DE_8
#undef DE_9
#undef DE_0
#undef DE_SS
#undef DE_ACUT
// Row 2
#undef DE_Q
#undef DE_W
#undef DE_E
#undef DE_R
#undef DE_T
#undef DE_Z
#undef DE_U
#undef DE_I
#undef DE_O
#undef DE_P
#undef DE_UDIA
#undef DE_PLUS
// Row 3
#undef DE_A
#undef DE_S
#undef DE_D
#undef DE_F
#undef DE_G
#undef DE_H
#undef DE_J
#undef DE_K
#undef DE_L
#undef DE_ODIA
#undef DE_ADIA
#undef DE_HASH
// Row 4
#undef DE_LABK
#undef DE_Y
#undef DE_X
#undef DE_C
#undef DE_V
#undef DE_B
#undef DE_N
#undef DE_M
#undef DE_COMM
#undef DE_DOT
#undef DE_MINS

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ ° │ ! │ " │ § │ $ │ % │ & │ / │ ( │ ) │ = │ ? │ ` │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │ * │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │   │   │   │   │   │   │   │   │   │   │   │ ' │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ > │   │   │   │   │   │   │   │ ; │ : │ _ │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#undef DE_DEG
#undef DE_EXLM
#undef DE_DQUO
#undef DE_SECT
#undef DE_DLR
#undef DE_PERC
#undef DE_AMPR
#undef DE_SLSH
#undef DE_LPRN
#undef DE_RPRN
#undef DE_EQL
#undef DE_QUES
#undef DE_GRV
// Row 2
#undef DE_ASTR
// Row 3
#undef DE_QUOT
// Row 4
#undef DE_RABK
#undef DE_SCLN
#undef DE_COLN
#undef DE_UNDS

/* Alted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │ „ │ ¡ │ “ │ ¶ │ ¢ │ [ │ ] │ | │ { │ } │ ≠ │ ¿ │   │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ « │ ∑ │ € │ ® │ † │ Ω │ ¨ │ ⁄ │ Ø │ π │ • │ ± │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │ Å │ ‚ │ ∂ │ ƒ │ © │ ª │ º │ ∆ │ @ │ Œ │ Æ │ ‘ │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ ≤ │ ¥ │ ≈ │ Ç │ √ │ ∫ │ ~ │ µ │ ∞ │ … │ – │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#undef DE_DLQU
#undef DE_IEXL
#undef DE_LDQU
#undef DE_PILC
#undef DE_CENT
#undef DE_LBRC
#undef DE_RBRC
#undef DE_PIPE
#undef DE_LCBR
#undef DE_RCBR
#undef DE_NEQL
#undef DE_IQUE
// Row 2
#undef DE_LDAQ
#undef DE_NARS
#undef DE_EURO
#undef DE_REGD
#undef DE_DAGG
#undef DE_OMEG
#undef DE_DIAE
#undef DE_FRSL
#undef DE_OSTR
#undef DE_PI
#undef DE_BULT
#undef DE_PLMN
// Row 3
#undef DE_ARNG
#undef DE_SLQU
#undef DE_PDIF
#undef DE_FHK
#undef DE_COPY
#undef DE_FORD
#undef DE_MORD
#undef DE_INCR
#undef DE_AT
#undef DE_OE
#undef DE_AE
#undef DE_LSQU
// Row 4
#undef DE_LTEQ
#undef DE_YEN
#undef DE_AEQL
#undef DE_CCCE
#undef DE_SQRT
#undef DE_INTG
#undef DE_TILD
#undef DE_MICR
#undef DE_INFN
#undef DE_ELLP
#undef DE_NDSH

/* Shift+Alted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
 * │   │ ¬ │ ” │   │ £ │ ﬁ │   │ \ │ ˜ │ · │ ¯ │ ˙ │ ˚ │     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
 * │     │ » │   │ ‰ │ ¸ │ ˝ │ ˇ │ Á │ Û │   │ ∏ │   │  │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐  │
 * │      │   │ Í │ ™ │ Ï │ Ì │ Ó │ ı │   │ ﬂ │   │   │   │  │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴──┤
 * │    │ ≥ │ ‡ │ Ù │   │ ◊ │ ‹ │ › │ ˘ │ ˛ │ ÷ │ — │        │
 * ├────┴┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┼───┴─┬─┴──┬─────┤
 * │     │    │     │                       │     │    │     │
 * └─────┴────┴─────┴───────────────────────┴─────┴────┴─────┘
 */
// Row 1
#undef DE_NOT
#undef DE_RDQU
#undef DE_PND
#undef DE_FI
#undef DE_BSLS
#undef DE_STIL
#undef DE_MDDT
#undef DE_MACR
#undef DE_DOTA
#undef DE_RNGA
// Row 2
#undef DE_RDAQ
#undef DE_PERM
#undef DE_CEDL
#undef DE_DACU
#undef DE_CARN
#undef DE_AACU
#undef DE_UCIR
#undef DE_NARP
#undef DE_APPL
// Row 3
#undef DE_IACU
#undef DE_TM
#undef DE_IDIA
#undef DE_IGRV
#undef DE_OACU
#undef DE_DLSI
#undef DE_FL
// Row 4
#undef DE_GTEQ
#undef DE_DDAG
#undef DE_UGRV
#undef DE_LOZN
#undef DE_LSAQ
#undef DE_RSAQ
#undef DE_BREV
#undef DE_OGON
#undef DE_DIV
#undef DE_MDSH
                              //

