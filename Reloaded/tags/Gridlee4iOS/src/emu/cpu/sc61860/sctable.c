
static void sc61860_instruction(sc61860_state *cpustate)
{
	int oper=READ_OP(cpustate);
	if ((oper&0xc0)==0x80) {
		sc61860_load_imm_p(cpustate, oper&0x3f);cpustate->icount-=2;
	} else if ((oper&0xe0)==0xe0) {
		sc61860_call(cpustate, READ_OP(cpustate)|((oper&0x1f)<<8));cpustate->icount-=7;
	} else {
		switch(oper) {
		case 0: sc61860_load_imm(cpustate, I, READ_OP(cpustate));cpustate->icount-=4;break;
		case 1: sc61860_load_imm(cpustate, J, READ_OP(cpustate));cpustate->icount-=4;break;
		case 2: sc61860_load_imm(cpustate, A, READ_OP(cpustate));cpustate->icount-=4;break;
		case 3: sc61860_load_imm(cpustate, B, READ_OP(cpustate));cpustate->icount-=4;break;
		case 4: sc61860_inc_load_dp(cpustate, XL);cpustate->icount-=6;break;
		case 5: sc61860_dec_load_dp(cpustate, XL);cpustate->icount-=6;break;
		case 6: sc61860_inc_load_dp(cpustate, YL);cpustate->icount-=6;break;
		case 7: sc61860_dec_load_dp(cpustate, YL);cpustate->icount-=6;break;
		case 8: sc61860_copy(cpustate, cpustate->ram[I]);break;
		case 9: sc61860_exchange(cpustate, cpustate->ram[I]);break;
		case 10: sc61860_copy(cpustate, cpustate->ram[J]);break;
		case 11: sc61860_exchange(cpustate, cpustate->ram[J]);break;
		case 12: sc61860_add_bcd_a(cpustate);cpustate->icount-=7;break;
		case 13: sc61860_sub_bcd_a(cpustate);cpustate->icount-=7;break;
		case 14: sc61860_add_bcd(cpustate);cpustate->icount-=7;break;
		case 15: sc61860_sub_bcd(cpustate);cpustate->icount-=7;break;
		case 16: sc61860_load_dp(cpustate);cpustate->icount-=8;break;
		case 17: sc61860_load_dl(cpustate);cpustate->icount-=5;break;
		case 18: sc61860_load_imm_p(cpustate, READ_OP(cpustate));cpustate->icount-=4;break;
		case 19: sc61860_load_imm_q(cpustate, READ_OP(cpustate));cpustate->icount-=4;break;
		case 20: sc61860_add_word(cpustate);cpustate->icount-=5;break;
		case 21: sc61860_sub_word(cpustate);cpustate->icount-=5;break;
		case 24: sc61860_copy_ext(cpustate, cpustate->ram[I]);break;
		case 25: sc61860_exchange_ext(cpustate, cpustate->ram[I]);break;
		case 26: sc61860_copy_ext(cpustate, cpustate->ram[J]);break;
		case 27: sc61860_exchange_ext(cpustate, cpustate->ram[J]);break;
		case 28: sc61860_shift_right_nibble(cpustate);cpustate->icount-=5;break;
		case 29: sc61860_shift_left_nibble(cpustate);cpustate->icount-=5;break;
		case 30: sc61860_fill(cpustate);cpustate->icount-=5;break;
		case 31: sc61860_fill_ext(cpustate);cpustate->icount-=4;break;
		case 32: sc61860_store_p(cpustate);cpustate->icount-=2;break;
		case 33: sc61860_store_q(cpustate);cpustate->icount-=2;break;
		case 34: sc61860_store_r(cpustate);cpustate->icount-=2;break;
		case 36: sc61860_inc_load_dp_load(cpustate);cpustate->icount-=7;break;
		case 37: sc61860_dec_load_dp_load(cpustate);cpustate->icount-=7;break;
		case 38: sc61860_inc_load_dp_store(cpustate);cpustate->icount-=7;break;
		case 39: sc61860_dec_load_dp_store(cpustate);cpustate->icount-=7;break;
		case 40: sc61860_jump_rel_plus(cpustate, !cpustate->zero);cpustate->icount-=4;break;
		case 41: sc61860_jump_rel_minus(cpustate, !cpustate->zero);cpustate->icount-=4;break;
		case 42: sc61860_jump_rel_plus(cpustate, !cpustate->carry);cpustate->icount-=4;break;
		case 43: sc61860_jump_rel_minus(cpustate, !cpustate->carry);cpustate->icount-=4;break;
		case 44: sc61860_jump_rel_plus(cpustate, TRUE);cpustate->icount-=4;break;
		case 45: sc61860_jump_rel_minus(cpustate, TRUE);cpustate->icount-=4;break;
		case 47: sc61860_loop(cpustate);cpustate->icount-=7;break;
		case 48: sc61860_load_imm_p(cpustate, cpustate->ram[A]);cpustate->icount-=2;break;
		case 49: sc61860_load_imm_q(cpustate, cpustate->ram[A]);cpustate->icount-=2;break;
		case 50: sc61860_load_r(cpustate);cpustate->icount-=2;break;
		case 52: sc61860_push(cpustate);cpustate->icount-=3;break;
		case 53: sc61860_copy_int(cpustate, cpustate->ram[I]);break;
		case 55: sc61860_return(cpustate);cpustate->icount-=4;break;
		case 56: sc61860_jump_rel_plus(cpustate, cpustate->zero);cpustate->icount-=4;break;
		case 57: sc61860_jump_rel_minus(cpustate, cpustate->zero);cpustate->icount-=4;break;
		case 58: sc61860_jump_rel_plus(cpustate, cpustate->carry);cpustate->icount-=4;break;
		case 59: sc61860_jump_rel_minus(cpustate, cpustate->carry);cpustate->icount-=4;break;
		case 64: sc61860_inc(cpustate, I);cpustate->icount-=4;break;
		case 65: sc61860_dec(cpustate, I);cpustate->icount-=4;break;
		case 66: sc61860_inc(cpustate, A);cpustate->icount-=4;break;
		case 67: sc61860_dec(cpustate, A);cpustate->icount-=4;break;
		case 68: sc61860_add(cpustate, cpustate->p,cpustate->ram[A]);cpustate->icount-=3;break;
		case 69: sc61860_sub(cpustate, cpustate->p,cpustate->ram[A]);cpustate->icount-=3;break;
		case 70: sc61860_and(cpustate, cpustate->p,cpustate->ram[A]);cpustate->icount-=3;break;
		case 71: sc61860_or(cpustate, cpustate->p,cpustate->ram[A]);cpustate->icount-=3;break;
		case 72: sc61860_inc(cpustate, K);cpustate->icount-=4;break;
		case 73: sc61860_dec(cpustate, K);cpustate->icount-=4;break;
		case 74: sc61860_inc(cpustate, V);cpustate->icount-=4;break;
		case 75: sc61860_dec(cpustate, V);cpustate->icount-=4;break;
		case 76: sc61860_in_a(cpustate);cpustate->icount-=2;break;
		case 77: /*nopw*/;cpustate->icount-=2;break;
		case 78: sc61860_wait(cpustate);cpustate->icount-=6;break;
		case 79: sc61860_wait_x(cpustate, FALSE);cpustate->icount-=1;break;
		case 80: sc61860_inc_p(cpustate);cpustate->icount-=2;break;
		case 81: sc61860_dec_p(cpustate);cpustate->icount-=2;break;
		case 82: sc61860_store_ext(cpustate, A);cpustate->icount-=2;break;
		case 83: sc61860_store_ext(cpustate, cpustate->p);cpustate->icount-=2;break;
		case 84: sc61860_load_imm(cpustate, cpustate->p, READ_OP(cpustate));cpustate->icount-=3/*?*/;break; // undocumented
		case 85: sc61860_load_ext(cpustate, cpustate->p);cpustate->icount-=3;break;
		case 86: sc61860_load_imm(cpustate, cpustate->p, READ_OP(cpustate));cpustate->icount-=3/*?*/;break; // undocumented
		case 87: sc61860_load_ext(cpustate, A);cpustate->icount-=3;break;
		case 88: sc61860_swap(cpustate);cpustate->icount-=2;break;
		case 89: sc61860_load(cpustate);cpustate->icount-=2;break;
		case 90: sc61860_rotate_left(cpustate);cpustate->icount-=2;break;
		case 91: sc61860_pop(cpustate);cpustate->icount-=2;break;
		case 93: sc61860_out_a(cpustate);cpustate->icount-=3;break;
		case 95: sc61860_out_f(cpustate);cpustate->icount-=3;break;
		case 96: sc61860_and(cpustate, cpustate->p,READ_OP(cpustate));cpustate->icount-=4;break;
		case 97: sc61860_or(cpustate, cpustate->p,READ_OP(cpustate));cpustate->icount-=4;break;
		case 98: sc61860_test(cpustate, cpustate->p,READ_OP(cpustate));cpustate->icount-=4;break;
		case 99: sc61860_cmp(cpustate, cpustate->p,READ_OP(cpustate));cpustate->icount-=4;break;
		case 100: sc61860_and(cpustate, A,READ_OP(cpustate));cpustate->icount-=4;break;
		case 101: sc61860_or(cpustate, A,READ_OP(cpustate));cpustate->icount-=4;break;
		case 102: sc61860_test(cpustate, A,READ_OP(cpustate));cpustate->icount-=4;break;
		case 103: sc61860_cmp(cpustate, A,READ_OP(cpustate));cpustate->icount-=4;break;
		case 105: sc61860_execute_table_call(cpustate);cpustate->icount-=3;break;
		case 107: sc61860_test_special(cpustate);cpustate->icount-=4;break;
		case 111: sc61860_wait_x(cpustate, TRUE);cpustate->icount-=1;break;
		case 112: sc61860_add(cpustate, cpustate->p,READ_OP(cpustate));cpustate->icount-=4;break;
		case 113: sc61860_sub(cpustate, cpustate->p,READ_OP(cpustate));cpustate->icount-=4;break;
		case 116: sc61860_add(cpustate, A,READ_OP(cpustate));cpustate->icount-=4;break;
		case 117: sc61860_sub(cpustate, A,READ_OP(cpustate));cpustate->icount-=4;break;
		case 120: sc61860_call(cpustate, READ_OP_ARG_WORD(cpustate));cpustate->icount-=8;break;
		case 121: sc61860_jump(cpustate, 1);cpustate->icount-=6;break;
		case 122: sc61860_prepare_table_call(cpustate);cpustate->icount-=9;break;
		case 124: sc61860_jump(cpustate, !cpustate->zero);cpustate->icount-=6;break;
		case 125: sc61860_jump(cpustate, !cpustate->carry);cpustate->icount-=6;break;
		case 126: sc61860_jump(cpustate, cpustate->zero);cpustate->icount-=6;break;
		case 127: sc61860_jump(cpustate, cpustate->carry);cpustate->icount-=6;break;
		case 192: sc61860_inc(cpustate, J);cpustate->icount-=4;break;
		case 193: sc61860_dec(cpustate, J);cpustate->icount-=4;break;
		case 194: sc61860_inc(cpustate, B);cpustate->icount-=4;break;
		case 195: sc61860_dec(cpustate, B);cpustate->icount-=4;break;
		case 196: sc61860_add_carry(cpustate);cpustate->icount-=3;break;
		case 197: sc61860_sub_carry(cpustate);cpustate->icount-=3;break;
		case 199: sc61860_cmp(cpustate, cpustate->p,cpustate->ram[A]);cpustate->icount-=3;break;
		case 200: sc61860_inc(cpustate, L);cpustate->icount-=4;break;
		case 201: sc61860_dec(cpustate, L);cpustate->icount-=4;break;
		case 202: sc61860_inc(cpustate, W);cpustate->icount-=4;break;
		case 203: sc61860_dec(cpustate, W);cpustate->icount-=4;break;
		case 204: sc61860_in_b(cpustate);cpustate->icount-=2;break;
		case 206: /*nopt*/;cpustate->icount-=3;break;
		case 208: sc61860_set_carry(cpustate);cpustate->icount-=2;break;
		case 209: sc61860_reset_carry(cpustate);cpustate->icount-=4;break;
		case 210: sc61860_rotate_right(cpustate);cpustate->icount-=2;break;
		case 212: sc61860_and_ext(cpustate);cpustate->icount-=6;break;
		case 213: sc61860_or_ext(cpustate);cpustate->icount-=6;break;
		case 214: sc61860_test_ext(cpustate);cpustate->icount-=6;break;
		case 216: sc61860_leave(cpustate);cpustate->icount-=2;break;
		case 218: sc61860_exam(cpustate, A, B);cpustate->icount-=3;break;
		case 219: sc61860_exam(cpustate, A, cpustate->p);cpustate->icount-=3;break;
		case 221: sc61860_out_b(cpustate);cpustate->icount-=2;break;
		case 223: sc61860_out_c(cpustate);cpustate->icount-=2;break;
		default: logerror("sc61860 illegal opcode at %.4x %.2x\n",cpustate->pc-1, oper);
		}
	}
}
