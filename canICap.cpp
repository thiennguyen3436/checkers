//all of this is placeholders until we have the classes implemented properly
void availableCaps(player player, piece[][] board){
	//also need a way to test whether or not it is a king. Can have a bool in the attributes?
	for(int i = 0; i < player.count; i++){
		a = player.list[i];
		if(a.team == 'w'){
			if((board[a.xpos+1][a.ypos+1] != NULL && board[a.xpos+2][a.ypos+2] == NULL)||(board[a.xpos-1][a.ypos+1] != NULL && board[a.xpos-2][a.ypos+2] == NULL)){
				a.canCap = true;
			}
			else{
				a.canCap = false;
			}
		}
		else if(a.team == 'b'){
			if((board[a.xpos+1][a.ypos-1] != NULL && board[a.xpos+2][a.ypos-2] == NULL)||(board[a.xpos-1][a.ypos-1] != NULL && board[a.xpos-2][a.ypos-2] == NULL)){
				a.canCap = true;
			}
			else{
				a.canCap = false;
			}
		}
	}
}

bool canIcap(player player){
	availableCaps(player, board);
	bool capturing = false;
	for(int i = 0; i < player.count; i++){
		a = player.list[i];
		if(a.canCap == true){
			capturing = true;
			break;
		}
	}
	return capturing
}

void capture(player player1, piece a){
	a.~piece();
	player1.count--;
}
//we also need to make sure that if a player has pieces that can capture they make at least one capture on their turn
//move is going to have to be a part of the player class instead of the piece class. Otherwise it's difficult to check whether or not the player has available captures
void move(){
	if (canIcap(*this)){

	}
}