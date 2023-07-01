#!/usr/bin/env python3

def translate_uc(c):
    if c == 't': return "KC_NO"
    return "UC(0x{:04X})".format(ord(c))

layer5 = "₁₂₃♀♂⚥ϰ⟨⟩₀‑ξtλχωκψγφϕςtιαεοσνρτδυtϵηπζβμϱϑθ"
layer6 = "¬∨∧⊥∡∥→∞∝∅‑Ξ√ΛℂΩ×ΨΓΦℚ∘⊂∫∀∃∈Σℕℝ∂Δ∇∪∩ℵΠℤ⇐⇔⇒↦Θ­"

layer = """
    KC_TRANSPARENT, {:<15} {:<15} {:<15} {:<15} {:<15} KC_TRANSPARENT,                                 KC_TRANSPARENT, {:<15} {:<15} {:<15} {:<15} {:<15} {:}
    KC_TRANSPARENT, {:<15} {:<15} {:<15} {:<15} {:<15} KC_TRANSPARENT,                                 KC_TRANSPARENT, {:<15} {:<15} {:<15} {:<15} {:<15} {:}
    KC_TRANSPARENT, {:<15} {:<15} {:<15} {:<15} {:<15} KC_TRANSPARENT,                                 KC_TRANSPARENT, {:<15} {:<15} {:<15} {:<15} {:<15} {:}
    KC_TRANSPARENT, {:<15} {:<15} {:<15} {:<15} {:<15}                                                                 {:<15} {:<15} {:<15} {:<15} {:<15} KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
"""

if False:
    while True:
        symbols = input()
        if symbols == "exit": break
        print(",\t".join([translate_uc(c) for c in symbols]))
if __name__ == "__main__":
    print(layer.format(*(translate_uc(c) + "," for c in layer6)))
