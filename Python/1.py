import math
import requests
from lxml import etree
import re
from queue import Queue
import threading
import time
 
 
def request_url(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.108 Safari/537.36',
        'Cookie': 'baidu_OCPC_pc=175b3166f6576342e1b8da3cbe982e3ac0707ac33bd7a0eb0fc4ed58457fb267a%3A2%3A%7Bi%3A0%3Bs%3A13%3A%22baidu_OCPC_pc%22%3Bi%3A1%3Bs%3A178%3A%22%22https%3A%5C%2F%5C%2Fbj.5i5j.com%5C%2F%3Fpmf_group%3Dbaidu%26pmf_medium%3Dppzq%26pmf_plan%3D%25E5%25B7%25A6%25E4%25BE%25A7%25E6%25A0%2587%25E9%25A2%2598%26pmf_unit%3D%25E6%25A0%2587%25E9%25A2%2598%26pmf_keyword%3D%25E6%25A0%2587%25E9%25A2%2598%26pmf_account%3D160%22%22%3B%7D; _ga=GA1.2.1211672380.1557302920; _gid=GA1.2.1890664603.1557302920; yfx_c_g_u_id_10000001=_ck19050816084013071518149335969; yfx_mr_n_10000001=baidu%3A%3Amarket_type_ppzq%3A%3A%3A%3A%3A%3A%3A%3A%3A%3A%25E6%25A0%2587%25E9%25A2%2598%3A%3Abj.5i5j.com%3A%3A%3A%3A%3A%3A%25E5%25B7%25A6%25E4%25BE%25A7%25E6%25A0%2587%25E9%25A2%2598%3A%3A%25E6%25A0%2587%25E9%25A2%2598%3A%3A160%3A%3Apmf_from_adv%3A%3Abj.5i5j.com%2F; yfx_mr_f_n_10000001=baidu%3A%3Amarket_type_ppzq%3A%3A%3A%3A%3A%3A%3A%3A%3A%3A%25E6%25A0%2587%25E9%25A2%2598%3A%3Abj.5i5j.com%3A%3A%3A%3A%3A%3A%25E5%25B7%25A6%25E4%25BE%25A7%25E6%25A0%2587%25E9%25A2%2598%3A%3A%25E6%25A0%2587%25E9%25A2%2598%3A%3A160%3A%3Apmf_from_adv%3A%3Abj.5i5j.com%2F; yfx_key_10000001=; _Jo0OQK=4EE84F9445D9BFF92A86A7F682BFE6DBC8F734FF62D5B7C4A4038B4C2A58EB5FE3A62387A4982A2CB8B73781BF81BA3EB1E83E96C00A59DFD841B6E2FD581963C90C57212F12283777C840763663251ADEB840763663251ADEBC1E2E9C73736BBD1F4F9294D3434308FGJ1Z1dw==; PHPSESSID=evf41us63lb9i9c0k1tc7pb1na; Hm_lvt_94ed3d23572054a86ed341d64b267ec6=1557302925,1557363884; domain=bj; yfx_f_l_v_t_10000001=f_t_1557302920249__r_t_1557363883528__v_t_1557368797898__r_c_1; _gat=1; Hm_lpvt_94ed3d23572054a86ed341d64b267ec6={}'.format(str(int(time.time())))
        
    }
    response = requests.get(url=url, headers=headers)
    content = response.content.decode('utf-8')
 
    times = 4
    while times > 0:
        if '<title>' in content:
            content = content
            break
        else:
            pattern = re.compile(r'<script>.*?href=\'(.*?)\';</script>')
            href = pattern.findall(content)[0]
            # print(href)
            content = request_url(href)
            times -= 1
            print(times)
    return content
 
 
class Thread_crawl(threading.Thread):
    def __init__(self, name, page_queue):
        # 参数一般以简短为主，所以选page
        threading.Thread.__init__(self)
        # 拿到任务队列
        self.page_queue = page_queue
        self.name = name
 
    def run(self):
        # # 开始时间
        # time_start = time.time()
        # print(self.name, "开始时间:", time_start)
        while True:
            # 线程停止条件
            if self.page_queue.empty():
                break
            else:
                page = self.page_queue.get()
                print(self.name, "将要从队列中取任务是：", page)
                content = request_url(page)
                self.get_data(content)
                print(self.name, '完成的任务是', page)
        # time_end = time.time()
        # print(self.name, '完成时间是：', time_end)
        # print(self.name, '耗时是：', time_end - time_start)
 
    def get_data(self, content):
        try:
            # print(content)
            tree = etree.HTML(content)
            li_list = tree.xpath('//div[@class="list-con-box"]/ul[@class="pList"]/li')
            print('11111', len(li_list))
            for li in li_list:
                title = li.xpath('.//h3//text()')[1]
                # print("名称：",title)
                type = li.xpath('.//div//text()')[13]
                # print("户型：",type)
                apartment = li.xpath('.//div//text()')[15]
                # print("小区名称：",apartment)
                follows_info = li.xpath('.//div//text()')[17]
                # print("关注消息：",follows_info)
                price = li.xpath('.//div//text()')[20]
                # print(price)
                info_dic = {
                    "名称": title,
                    "户型": type,
                    "小区名称": apartment,
                    "关注消息": follows_info,
                    "价钱": price
                }
                print(info_dic)
                with open('information.txt', 'a', encoding='utf-8') as fp:
                    fp.write(str(info_dic) + '\n')
        except:
            with open('error.txt', 'a', encoding='utf-8') as fp:
                fp.write(url)
        # with open('tecent_job.txt', 'a', encoding='utf-8') as fp:
        #     fp.write(info)
 
 
if __name__ == '__main__':
    # 任务开始时间
    t_start = time.time()
    print("主线程开始时间：", t_start)
    url = 'https://bj.5i5j.com/zufang/'
    # 1.创建任务队列：存放所有的page
    content = request_url(url)
    tree = etree.HTML(content)
    # num = tree.xpath('//div[@class="total-box noBor"]/span/text()')
    # print(num[0])
 
    a_list = tree.xpath('//ul[@class="new_di_tab sTab"]/a')[1:]
    # print(len(a_list))
    page_queue = Queue()
 
    for a in a_list:
        link = a.xpath('./@href')[0]
        url_old = 'https://bj.5i5j.com' + link
        content = request_url(url_old)
        tree = etree.HTML(content)
        num = tree.xpath('//div[@class="total-box noBor"]/span/text()')
        pages = math.ceil(int(num[0]) / 30)
        for i in range(1, pages + 1):
            url = url_old + 'n' + str(i)
            page_queue.put(url)
 
    # 2.生成线程：
    crawl_name = ['c1', 'c2', 'c3']
    crawl_thread = []
    for name in crawl_name:
        crawl = Thread_crawl(name, page_queue)
        crawl.start()
        crawl_thread.append(crawl)
        # join()不能写在这里，因为这样写就类似于单线程 c1完了才启动c2
 
    # 阻塞线程  让子线程都完成任务后，主线程再往下进行
    for thread in crawl_thread:
        thread.join()
 
    # 主进程结束时间
    t_end = time.time()
    print(t_end)
    print('完成时间是：', t_end - t_start)
