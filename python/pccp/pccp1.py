class Video_player:
    def __init__(self, video_len, pos, op_start, op_end):
        self.video_len = self.trasnfer_to_int(video_len)
        self.pos = self.trasnfer_to_int(pos)
        self.op_start = self.trasnfer_to_int(op_start)
        self.op_end =self.trasnfer_to_int(op_end)     
        
        # 오프닝 건너뛰기
        self.openning()
        
    def openning(self):
        if self.op_start <= self.pos and self.pos <= self.op_end:
            self.pos = self.op_end
            
            
    def trasnfer_to_int(self,time_str):
        min, sec = map(int, time_str.split(':')) 
        return  min*60 + sec


    def next(self):
        self.pos = self.pos + 10
        if self.pos >= self.video_len:
            self.pos = self.video_len
        self.openning()


    def prev(self):
        self.pos = self.pos - 10
        if self.pos < 0:
            self.pos = 0
        self.openning()

    def get_result(self):
        min = self.pos // 60
        sec = self.pos % 60
        
        str_number = "{:02}:{:02}".format(min,sec)
        return str_number

        
def solution(video_len, pos, op_start, op_end, commands):

    palyer1 = Video_player(video_len, pos, op_start, op_end)
    
    for cmd in commands:
        method = getattr(palyer1, cmd)
        method()
    
    return palyer1.get_result()


